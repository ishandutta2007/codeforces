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
	inline int read(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
}using namespace IO_BUFF;
const int N=1e4+5;
const int M=(1<<10);
int n,m,k,T,a[N];
short x[N],y[N],z[N];
int id[M],da[M],g[M];
int s,t;
#define GP GraPh
struct GraPh{
	struct node{
		short next,to,dis;
	}a[N*2+20];
	short head[N],cnt;
	void add(int u,int v,int w){
		a[++cnt].next=head[u];a[cnt].to=v;a[cnt].dis=w;head[u]=cnt;
	}
	void link(int u,int v,int w){
		add(u,v,w);add(v,u,0);
	}
	short dis[N],pre[N];
	bool bfs(){
		queue<short>q;
		memset(dis,-1,sizeof(dis));
		q.push(s);
		while(!q.empty()){
			const short u=q.front();
			q.pop();
			for(int i=head[u];i;i=a[i].next){
				const int v=a[i].to;
				if(a[i].dis && dis[v]==-1){
					dis[v]=dis[u]+1;
					pre[v]=i;
					q.push(v);
					if(v==n)break;
				}
			}
			if(~dis[n])break;
		}
		if(~dis[n])return 1;
		else return 0;
	}
	int work(){
		int ans=0;
		while(bfs()){
			int u=t;
			short tmp=3e4;
			while(u!=s){
				tmp=min(tmp,a[pre[u]].dis);
				u=a[pre[u]^1].to;
			}
			u=t;ans+=tmp;
			while(u!=s){
				a[pre[u]].dis-=tmp;
				a[pre[u]^1].dis+=tmp;
				u=a[pre[u]^1].to;
			}
		}
		return ans;
	}
}f[M];
int main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();m=read();k=read();T=read();
	const int S=(1<<k)-1;
	for(int i=1;i<=k;i++)id[1<<(i-1)]=i;
	s=1;t=n;
	f[0].cnt=1;
	for(int i=1;i<=m;i++){
		x[i]=read();y[i]=read();z[i]=read();
		f[0].link(x[i],y[i],z[i]);
	}
	da[0]=f[0].work();
	for(int i=1;i<=S;i++){
		const int tmp=(i&(-i));
		f[i]=f[i^tmp];
		f[i].link(x[id[tmp]],y[id[tmp]],25);
		da[i]=da[i^tmp]+f[i].work();
	}
	while(T--){
		for(int i=1;i<=k;i++)a[i]=read();
		for(int i=1;i<=S;i++){
			const int tmp=(i&(-i));
			g[i]=g[i^tmp]+a[id[tmp]];
		}
		int ans=1e9;
		for(int i=0;i<=S;i++){
			ans=min(ans,g[i]+da[S^i]);
		}
		print(ans);
	}
	Flush();
	return 0;
}