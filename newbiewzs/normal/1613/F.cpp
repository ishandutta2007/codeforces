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
const int N=2.5e5+5;
const int mod=998244353;
const int g=3;
const int fg=332748118;
int n,x,y,d[N*4],fac[N*4],ans;
vi v[N*4],cl,cr;
int add(int x,int y){
	return (x+y>=mod?x+y-mod:x+y);
}
int siz,r[N*4],m;
void prework(int x){
	m=1;siz=0;
	while(m<x){
		m<<=1;siz++;
	}
	for(int i=0;i<m;i++)r[i]=((r[i>>1]>>1)|((i&1)<<(siz-1)));
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
void ntt(vi &a,int len,int op){
	for(int i=0;i<len;i++){
		if(r[i]<i){
			swap(a[r[i]],a[i]);	
		}	
	}
	for(int i=1;i<len;i<<=1){
		const int w=(op==1)?ksm(g,(mod-1)/(i*2)):ksm(fg,(mod-1)/(i*2));
		for(int k=0;k<len;k+=i*2){
			for(int j=0,h=1;j<i;j++,h=1ll*h*w%mod){
				int x=a[k+j];
				int y=1ll*a[i+k+j]*h%mod;
				a[k+j]=add(x,y);
				a[i+k+j]=(x-y+mod)%mod;
			}
		}
	}
	if(op==-1){
		const int inv=ksm(len,mod-2);
		for(int i=0;i<len;i++)a[i]=1ll*a[i]*inv%mod;
	}
}
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
void solve(int u,int l,int r){
	if(l==r){
		v[u].resize(2);
		v[u][0]=1;
		v[u][1]=d[l];
		return ;
	}
	solve(ls,l,mid);
	solve(rs,mid+1,r);
	int tmp=v[ls].size()+v[rs].size();
	prework(tmp);
	cl.resize(m+5);
	cr.resize(m+5);
	v[u].resize(m+5);
	for(int i=0;i<cl.size();i++)cl[i]=cr[i]=v[u][i]=0;
	for(int i=0;i<v[ls].size();i++)cl[i]=v[ls][i];
	for(int i=0;i<v[rs].size();i++)cr[i]=v[rs][i];
	ntt(cl,m,1);
	ntt(cr,m,1);
	for(int i=0;i<m;i++)v[u][i]=1ll*cl[i]*cr[i]%mod;
	ntt(v[u],m,-1);
	while(v[u].size() && v[u].back()==0)v[u].pop_back();
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		d[x]++;
		d[y]++;
	}
	for(int i=2;i<=n;i++)d[i]--;
	solve(1,1,n);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<=min(n-1,(int)v[1].size());i++){
		if(i&1)ans=(ans-1ll*fac[n-i]*v[1][i]%mod+mod)%mod;
		else ans=add(ans,1ll*fac[n-i]*v[1][i]%mod);
	}
	cout<<ans;
	return 0;
}