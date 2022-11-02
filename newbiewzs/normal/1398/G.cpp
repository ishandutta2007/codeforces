#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int mod=998244353;
const int g=3;
const int fg=332748118;
const int N=1e6+5;
const int M=1e6;
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
inline int del(const int &x,const int &y){
	return (x-y<0?x-y+mod:x-y);
}
int n,q,x,y,l[N];
int r[N],ta[N],tb[N],ycl[N],m,siz;
int tx,ans[N];
void ntt(int a[],int len,int op){
	for(int i=0;i<len;i++){
		if(r[i]<i)swap(a[r[i]],a[i]);
	}
	for(int i=1;i<len;i<<=1){
		const int w=(op==1?ksm(g,(mod-1)/(i*2)):ksm(fg,(mod-1)/(i*2)));
		ycl[0]=1;
		for(int j=1;j<i;j++){
			ycl[j]=1ll*ycl[j-1]*w%mod;
		}
		for(int k=0;k<len;k+=(i<<1)){
			for(int j=0;j<i;j++){
				const int x=a[k+j];
				const int y=1ll*ycl[j]*a[i+k+j]%mod;
				a[k+j]=add(x,y);
				a[i+k+j]=del(x,y);
			}
		}
	}
	if(op==-1){
		const int inv=ksm(len,mod-2);
		for(int i=0;i<len;i++)a[i]=1ll*a[i]*inv%mod;
	}
}
void mul(int a[],int la,int b[],int lb){
	int tmp=la+lb;m=1;
	while(m<tmp)m*=2,siz++;
	for(int i=0;i<m;i++)r[i]=((r[i>>1]>>1)|((i&1)<<(siz-1)));
	ntt(a,m,1);ntt(b,m,1);
	for(int i=0;i<m;i++)a[i]=1ll*a[i]*b[i]%mod;
	ntt(a,m,-1);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();x=read();y=read();
	for(int i=0;i<=n;i++)l[i]=read();
	for(int i=0;i<=n;i++){
		ta[l[i]]=1;
		tb[x-l[i]]=1;
	}
	mul(ta,x,tb,x);
	for(int i=x+1;i<=m;i++){
		if(ta[i]){
			int tmp=i-x;
			if(2*(tmp+y)<=M)ans[2*(tmp+y)]=2*(tmp+y);
		}
	}
	for(int i=1;i<=M;i++){
		if(ans[i]==i){
			for(int k=i;k<=M;k+=i){
				ans[k]=max(ans[k],i);
			}
		}
	}
	q=read();
	for(int i=1;i<=q;i++){
		tx=read();
		if(ans[tx])cout<<ans[tx]<<" ";
		else cout<<"-1 ";
	}
	return 0;
}