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
// #pragma GCC optimize(3)
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
char aa;
const int N=3001;
int n,x[N],y[N];
vector<short> v[N];
int siz[N],deep[N];
unsigned f[N][N][2][2];
const unsigned cn=-1;
short g[N][N],fu[N];
vector<pair<short,short>>h[N][2];
void dfs(int u,int fa){
	siz[u]=1;deep[u]=deep[fa]+1;fu[u]=fa;
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs(i,u);
		siz[u]+=siz[i];
	}
}
short L[N][N];
int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	if(L[x][y])return L[x][y];
	if(x==y)return x;
	L[x][y]=lca(fu[x],y);
	return L[x][y];
}
void dp(int u,int fa,int x,int y){
	g[u][y]=x;
	for(auto i:v[u]){
		if(i==fa)continue;
		dp(i,u,x,y);
	}
}
char bb;
signed main(){
	#ifdef newbiewzs
		cerr<<"Memory:"<<(&bb-&aa)/1024/1024<<'\n';
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	//char cc;
	//cout<<(&cc-&aa)/1024/1024<<'\n';
	for(int i=1;i<n;i++){
		x[i]=read();y[i]=read();
		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(auto k:v[i]){
			dp(k,i,k,i);
		}
	}
	
	dfs(1,0);
	for(int i=1;i<=n;i++)for(int k=1;k<=n;k++)for(int j=0;j<=1;j++)for(int h=0;h<=1;h++)f[i][k][j][h]=cn;
	for(int i=1;i<=n;i++)f[i][i][0][0]=0;
	
	for(short i=1;i<=n;i++){
		for(short k=1;k<=n;k++){
			if(deep[i]>=deep[k])h[deep[i]-deep[k]][0].pb(mp(i,k)),h[deep[i]-deep[k]][0].pb(mp(k,i));
			if(i<k){
				h[deep[i]+deep[k]-2*deep[lca(i,k)]][1].pb(mp(i,k));
				h[deep[i]+deep[k]-2*deep[lca(i,k)]][1].pb(mp(k,i));
			}
		}
	}
	
	//  / x   WDNMD
	for(int i=0;i<=n;i++){
		for(auto G:h[i][0]){
			auto tx=G.fi;
			auto ty=G.se;
			for(auto k:v[tx]){
				if(deep[k]>deep[tx]){
					if(f[tx][ty][0][0]!=cn){
						
						if(f[k][ty][0][0]==cn)f[k][ty][0][0]=f[tx][ty][0][0]+(unsigned)siz[k]*(n-siz[g[k][ty]]);
						else f[k][ty][0][0]=max(f[k][ty][0][0],f[tx][ty][0][0]+(unsigned)siz[k]*(n-siz[g[k][ty]]));
					}
					if(f[tx][ty][0][1]!=cn){
						if(f[k][ty][0][1]==cn)f[k][ty][0][1]=f[tx][ty][0][1]+(unsigned)siz[k]*(n-siz[g[k][ty]]);
						else f[k][ty][0][1]=max(f[k][ty][0][1],f[tx][ty][0][1]+(unsigned)siz[k]*(n-siz[g[k][ty]]));
					}
				}
			}
			for(auto k:v[ty]){
				if(deep[k]<deep[ty]){
					if(f[tx][ty][0][0]!=cn){
						if(f[tx][k][0][1]==cn)f[tx][k][0][1]=f[tx][ty][0][0]+(unsigned)siz[tx]*(n-siz[ty]);
						else f[tx][k][0][1]=max(f[tx][k][0][1],f[tx][ty][0][0]+(unsigned)siz[tx]*(n-siz[ty]));
					}
					if(f[tx][ty][0][1]!=cn){
						if(f[tx][k][0][1]==cn)f[tx][k][0][1]=f[tx][ty][0][1]+(unsigned)siz[tx]*(n-siz[ty]);
						else f[tx][k][0][1]=max(f[tx][k][0][1],f[tx][ty][0][1]+(unsigned)siz[tx]*(n-siz[ty]));
					}
					
				}
				else {
					if(lca(tx,k)==k || lca(tx,k)==tx)continue;
					if(f[tx][ty][0][0]!=cn){
						if(f[tx][k][1][1]==cn)f[tx][k][1][1]=f[tx][ty][0][0]+(unsigned)siz[tx]*siz[k];
						else f[tx][k][1][1]=max(f[tx][k][1][1],f[tx][ty][0][0]+(unsigned)siz[tx]*siz[k]);
					}
					if(f[tx][ty][0][1]!=cn){
						if(f[tx][k][1][1]==cn)f[tx][k][1][1]=f[tx][ty][0][1]+(unsigned)siz[tx]*siz[k];
						else f[tx][k][1][1]=max(f[tx][k][1][1],f[tx][ty][0][1]+(unsigned)siz[tx]*siz[k]);
					}
				}
			}
		}
		for(auto G:h[i][1]){
			auto tx=G.fi;
			auto ty=G.se;
			for(auto k:v[tx]){
				if(deep[k]>deep[tx]){
					if(f[tx][ty][1][1]!=cn){
						if(f[k][ty][1][1]==cn)f[k][ty][1][1]=f[tx][ty][1][1]+(unsigned)siz[k]*siz[ty];
						else f[k][ty][1][1]=max(f[k][ty][1][1],f[tx][ty][1][1]+(unsigned)siz[k]*siz[ty]);
					}
				}
			}
			for(auto k:v[ty]){
				if(deep[k]>deep[ty]){
					if(f[tx][ty][1][1]!=cn){
						if(f[tx][k][1][1]==cn)f[tx][k][1][1]=f[tx][ty][1][1]+(unsigned)siz[tx]*siz[k];
						else f[tx][k][1][1]=max(f[tx][k][1][1],f[tx][ty][1][1]+(unsigned)siz[tx]*siz[k]);
					}
				}
			}
		}
	}
	unsigned ans=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(f[i][k][0][0]!=cn)ans=max(ans,f[i][k][0][0]);
			if(f[i][k][1][0]!=cn)ans=max(ans,f[i][k][1][0]);
			if(f[i][k][0][1]!=cn)ans=max(ans,f[i][k][0][1]);
			if(f[i][k][1][1]!=cn)ans=max(ans,f[i][k][1][1]);
		}
	}
	cout<<ans;
	return 0;
}