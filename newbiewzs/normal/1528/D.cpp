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
const int N=605;
int n,m,x,y,z;
vector<pii> v[N],g[N];
int dis[N],pd[N];
void dijkstra(int u){
	mem0x3f(dis);
	mem0(pd);
	queue<int>q;
	q.push(u);
	for(auto i:v[u]){
		dis[i.fi]=i.se;
	}
	while(1){
		int minn=1e15,u=0;
		for(int i=1;i<=n;i++)if(!pd[i] && dis[i]<minn){
			minn=dis[i];
			u=i;
		}
		if(!u)break;
		pd[u]=1;
		for(auto i:v[u]){
			if(dis[(i.fi+dis[u]-1)%n+1]>dis[u]+i.se){
				dis[(i.fi+dis[u]-1)%n+1]=dis[u]+i.se;
			}
		}
		for(auto i:g[u]){
			if(dis[(i.fi)]>dis[u]+i.se){
				dis[(i.fi)]=dis[u]+i.se;
			}
		}
	}
	dis[u]=0;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();z=read();
		x++;y++;
		v[x].pb(mp(y,z));
	}
	for(int i=1;i<n;i++){
		g[i].pb(mp(i+1,1));
	}
	g[n].pb(mp(1,1));
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int k=1;k<=n;k++){
			cout<<dis[k]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}