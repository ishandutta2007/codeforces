#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
//#pragma GCC optimize(3)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;
const int N=2e5+5;
int n,m,summ,a[N],bit[40];
int sa[1000000],sb[30][1000000],c[1000000],ta,tb;
int ins(int x){
	for(int i=m;i>=0;i--){
		if(x&(1ll<<i)){
			if(!bit[i]){
				bit[i]=x;return 0;
			}
			else x^=bit[i];
		}
	}
	return 1;
}
int w;
void sxor(int v[],int op){
	for(int i=2,k=1;k<(1<<w);i<<=1,k<<=1){
		for(int j=0;j<(1<<w);j+=i){
			for(int l=0;l<k;l++){
				int x=v[j+l];
				int y=v[j+l+k];
				v[j+l]=(1ll*op*(x+y)%mod+mod)%mod;
				v[j+l+k]=(1ll*op*(x-y+mod)%mod+mod)%mod;
			}
		}
	}
}
int pw[N],ans[N];
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)summ+=ins(a[i]);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=1ll*pw[i-1]*2%mod;
	int B=max(m/2-1,0ll);
	for(int i=0;i<(1<<(B+1));i++){
		int tmp=0;
		bool flag=0;
		for(int k=0;k<=B;k++){
			if(i&(1<<(k))){
				tmp^=bit[k];
				if(!bit[k])flag=1;
			}
		}
		if(!flag){
			sa[tmp]++;
		}
	}
	for(int i=0;i<(1<<(m-B));i++){
		bool flag=0;
		int tmp=0;
		for(int k=1;k<=m-B;k++){
			if(i&(1ll<<(k-1))){
				tmp^=bit[B+k];
				if(!bit[B+k])flag=1;
			}
		}
		if(!flag){
			int tep=(tmp&((1ll<<(B+1))-1));
			tmp>>=(B+1);
			sb[bc(tmp)][tep]++;
		}
	}
	w=max(B+1,m-B);
	for(int i=0;i<=w;i++){
		sxor(sb[i],1);
		sxor(sa,1);
		for(int k=0;k<(1<<w);k++){
			c[k]=1ll*sb[i][k]*sa[k]%mod;
		}
		sxor(c,(mod+1)>>1);
		sxor(sa,(mod+1)>>1);
		for(int k=0;k<(1<<w);k++){
			ans[bc(k)+i]=add(ans[bc(k)+i],1ll*c[k]*pw[summ]%mod);
		}
	}
	for(int i=0;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}