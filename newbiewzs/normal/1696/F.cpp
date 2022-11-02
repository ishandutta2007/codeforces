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
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
#define dsi(x,y,z) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<" ; "<<"the "<<#z<<" = "<<z<<'\n';
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
const int N=105;
int T,n,vis[N],col[N];
bitset<N>a[N][N];
vi v[N];
vector<pii>cd;
char c[N][N][N];
void dfs(int u,int id){
	vis[u]=1;
	col[u]=id;
	for(auto i:v[u]){
		if(vis[i])continue;
		dfs(i,id);
	}
}
map<pii,int>ma;
bool check(int uu,int vv){
	queue<pii>q;cd.clear();ma.clear();
	q.push(mp(uu,vv));
	ma[mp(uu,vv)];ma[mp(vv,uu)];
	int summ=0;
	while(!q.empty()){
		auto u=q.front();
		cd.pb(u);
		q.pop();
		summ++;
		for(int i=1;i<=n;i++){
			if(a[i][u.fi][u.se]==1){
				if(!ma.count(mp(i,u.se))){
					q.push(mp(i,u.se));
					ma[mp(i,u.se)];
					ma[mp(u.se,i)];
				}				
			}
			if(a[i][u.se][u.fi]==1){
				if(!ma.count(mp(i,u.fi))){
					q.push(mp(i,u.fi));
					ma[mp(i,u.fi)];
					ma[mp(u.fi,i)];
				}
				
			}
		}
	}
	//dsi(uu,vv,summ);
	//cerr<<'\n';
	return (summ==n-1);
}
int f[N];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
int d[N][N];
void dp(int u,int fa,int id,int deep){
	d[id][u]=deep;
	for(auto i:v[u]){
		if(i==fa)continue;
		dp(i,u,id,deep+1);
	}
}
bool erch(){
	for(int i=1;i<=n;i++)f[i]=i,v[i].clear();
	for(auto i:cd){
		if(find(i.fi)==find(i.se))return 0;
		f[find(i.fi)]=find(i.se);
	}
	for(auto i:cd){
		v[i.fi].pb(i.se);
		v[i.se].pb(i.fi);
	}
	for(int i=1;i<=n;i++)dp(i,0,i,0);
	for(int i=1;i<=n;i++){
		for(int k=i+1;k<=n;k++){
			for(int j=1;j<=n;j++){
				if(d[i][j]==d[k][j]){
					if(!a[i][k][j])return 0;
				}
				else if(a[i][k][j])return 0;
			}
		}
	}
	return 1;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();mem0(vis);mem0(col);
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				scanf("%s",c[i][k]+1);
				for(int j=1;j<=n;j++){
					a[i][k][j]=a[k][i][j]=c[i][k][j]-'0';
				}
				if(a[i][k].count())v[i].pb(k),v[k].pb(i);
			}
		}
		bool flag=0;int siz=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				dfs(i,siz);
				siz++;
				if(siz>2)goto qwq;
			}
		}
		if(siz==1)goto qwq;
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
				if(col[i]!=col[k] && check(i,k)){
					if(!erch())continue;
					flag=1;
					puts("YES");
					for(auto j:cd){
						cout<<j.fi<<" "<<j.se<<'\n';
					}
					goto qwq;
				}
			}
		}
		qwq:;
		if(!flag)puts("NO");
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				a[i][k].reset();
			}
			v[i].clear();
		}
	}
	return 0;
}