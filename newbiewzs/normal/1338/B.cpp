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
//#define int long long
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
/*namespace CFConTest{
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
using namespace CFConTest;*/
const int N=1e5+5;
int n,rt,d[N],a[N],b[N];
vi v[N];
int deep[N],maxx[N],mixx[N],flag;int siz[N],f[N][2];
void dfs(int u,int fa){
	deep[u]=maxx[u]=deep[fa]+1;siz[u]=1; 
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs(i,u);
		siz[u]+=siz[i];
		f[u][1]|=f[i][0];
		f[u][0]|=f[i][1];
	}
	if(siz[u]==1)f[u][0]=1;
	if(f[u][0] && f[u][1])flag=1;
}
int g[N];
void dp(int u,int fa){
	bool bj=0;
	for(auto i:v[u]){
		if(i==fa)continue;
		dp(i,u);
		if(siz[i]==1)bj=1;
		else g[u]+=g[i]+1;
	}
	if(bj)g[u]++;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<n;i++){
		a[i]=read();b[i]=read();
		d[a[i]]++;d[b[i]]++;
		v[a[i]].pb(b[i]);
		v[b[i]].pb(a[i]);
	}
	for(int i=1;i<=n;i++)if(d[i]>=2)rt=i;
	dfs(rt,0);
	if(flag)cout<<3<<" ";
	else cout<<1<<" ";
	dp(rt,0);
	cout<<g[rt];
	return 0;
}