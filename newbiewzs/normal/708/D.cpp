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
#define dsi(x,y,z) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<" the "<<#z<<" = "<<z<<'\n';
#define fer(i,a,b) for(int i=a;i<=b;i++)
#define erf(i,a,b) for(int i=b;i>=a;i--)
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
int n,m,u,v,c,f;
struct node{
	int next,to,dis,val;
}a[N*20];
int head[N*5],cnt=1,in[N],ou[N];
void link(int u,int v,int w,int vv){
	a[++cnt]={head[u],v,w,vv};
	head[u]=cnt;
}
void add(int u,int v,int ww,int vv){
	link(u,v,ww,vv);
	link(v,u,0,-vv);
}
void add(int u,int v,int zz,int ww,int vv){
	in[v]+=zz;
	ou[u]+=zz;
	link(u,v,ww-zz,vv);
	link(v,u,0,-vv);
}
int S,T,pd[N*5],dis[N*5],deep[N*5];
bool bfs(){
	queue<int>q;
	mem0x3f(dis);
	mem0(deep);
	q.push(S);dis[S]=0;deep[S]=1;
	while(q.size()){
		int u=q.front();q.pop();
		pd[u]=0;
		for(int i=head[u];i;i=a[i].next){
			if(a[i].dis && dis[a[i].to]>dis[u]+a[i].val){
				dis[a[i].to]=dis[u]+a[i].val;
				deep[a[i].to]=deep[u]+1;
				if(!pd[a[i].to]){
					pd[a[i].to]=1;
					q.push(a[i].to);
				}
			}
		}
	}
	return (deep[T]>0);
}
int ans=0;
int dfs(int u,int flow){
	if(u==T || !flow)return flow;
	int summ=0;
	for(int i=head[u];i;i=a[i].next){
		if(a[i].dis && deep[a[i].to]==deep[u]+1 && dis[a[i].to]==dis[u]+a[i].val){
			int tmp=dfs(a[i].to,min(a[i].dis,flow));
			flow-=tmp;
			a[i].dis-=tmp;
			a[i^1].dis+=tmp;
			ans+=a[i].val*tmp;
			summ+=tmp;
			if(!flow)break;
		}
	}
	return summ;
}
void dinic(){
	while(bfs()){
		int tep=dfs(S,1000000000);
	//	dbg(tep);
	}
	cout<<ans;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();T=n+1;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>c>>f;
		if(c>=f){
			add(v,u,0,f,1);
			if(c!=f)add(u,v,0,c-f,1);
			add(u,v,0,100000000,2);
		}
		else{
			ans+=f-c;
			add(v,u,0,f-c,0);
			add(v,u,0,c,1);
			add(u,v,0,100000000,2);
		}
		add(u,v,f,f,0);
	}
	add(n,1,100000000,0);
	for(int i=1;i<=n;i++){
		if(in[i]>ou[i]){
			add(S,i,in[i]-ou[i],0);
		}
		if(in[i]<ou[i]){
			add(i,T,ou[i]-in[i],0);
		}
	}
	dinic();
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}