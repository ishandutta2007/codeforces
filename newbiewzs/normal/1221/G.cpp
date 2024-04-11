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
// #pra gma GCC opti mize(3)
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
const int N=45;
int n,m,x,y,ans,pd[N][N];
ll a[N];
vi v[N];
int vis[N];
int val[N],flag=0,f[1<<21];
void dfs(int u,int ne){
	vis[u]=1;
	val[u]=ne;
	for(const auto i:v[u]){
		if(vis[i]){
			if(val[i]!=(ne^1))flag=0;
		}
		else dfs(i,ne^1);
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	if(m==0){
		cout<<0;return 0;
	}
	for(int i=1;i<=m;i++){
		x=read();y=read();
		a[x]|=(1ll<<y);
		a[y]|=(1ll<<x);
		pd[x][y]=pd[y][x]=1;
		v[x].pb(y);
		v[y].pb(x);
	}
	ans=(1ll<<n);
	flag=1;
	int siz=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			siz++;
			dfs(i,0);
		}
	}
	ans-=(1ll<<siz);
	if(flag)ans+=(1ll<<siz);
	siz=0;
	for(int i=1;i<=n;i++){
		if(!a[i])siz++;
	}
	ans+=2*(1ll<<siz);
	
	
	int S=(n/2);
	for(int i=0;i<(1<<(n-S));i++){
		bool bj=0;
		for(int k=S+1;k<=n;k++){
			for(int j=k+1;j<=n;j++){
				if(!pd[k][j])continue;
				if(!(i&(1<<(k-S-1))) && !(i&(1<<(j-S-1))))bj=1;
			}
		}
		if(bj)continue;
		f[i]=1;
	}
	for(int k=1;k<=n-S;k++){
		for(int i=0;i<(1<<(n-S));i++){
			if(!(i&(1<<(k-1))))f[i]+=f[i|(1<<(k-1))];
		}
	}
	for(int i=0;i<(1<<S);i++){
		int tmp=0;
		for(int k=1;k<=S;k++){
			if((i&(1<<(k-1))))continue;
			for(int j=S+1;j<=n;j++){
				if(pd[k][j]){
					tmp|=(1<<(j-S-1));
				}
			}
		}
		bool bj=0;
		for(int k=1;k<=S;k++){
			for(int j=k+1;j<=S;j++){
				if(!pd[k][j])continue;
				if(!(i&(1<<(k-1))) && !(i&(1<<(j-1))))bj=1;
			}
		}
		if(bj)continue;
		ans-=2*f[tmp];
	}
	cout<<ans;
	return 0;
}