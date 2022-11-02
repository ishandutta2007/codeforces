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
#define fer(i,a,b) for(int i=a;i<=b;i++)
#define ref(i,a,b) for(int i=b;i>=a;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(a) a.begin(),a.end()
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
const int N=1e7+5;
const int M=755;
int n,ch[N][2],fail[N],siz[N],kk[M],rt,tot;
string c[M];
void insert(int id){
	int len=c[id].length();
	int u=rt;
	for(int i=0;i<len;i++){
		if(!ch[u][c[id][i]-'a'])ch[u][c[id][i]-'a']=++tot;
		u=ch[u][c[id][i]-'a'];
	}
	if(siz[u])kk[siz[u]]=1;
	siz[u]=id;
}
void build(){
	queue<int>q;
	for(int i=0;i<2;i++){
		if(ch[0][i]){
			q.push(ch[0][i]);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<2;i++){
			if(!ch[u][i])ch[u][i]=ch[fail[u]][i];
			else{
				int v=ch[u][i];
				fail[v]=ch[fail[u]][i];
				q.push(v);
			}
		}
	}
}
bitset<M>g[M];
void work(int id){
	int len=c[id].length();
	int u=rt;
	for(int i=0;i<len;i++){
		u=ch[u][c[id][i]-'a'];
		int v=u,val=0;
		while(v){
			if(siz[v] && siz[v]!=id){
				val=siz[v];break;
			}
			v=fail[v];
		}
		if(val)g[id][val]=1;
		int vv=v;
		v=u;
		while(v){
			if(siz[v] && siz[v]!=id)break;
			int kel=fail[v];
			fail[v]=vv;
			v=kel;
		}
	}
}
namespace L{
	struct node{
		int next,to,dis;
	}a[M*M*3];
	int head[M*3],cnt=1;
	void add(int e,int r,int t){
		a[++cnt]={head[e],r,t};
		head[e]=cnt;
	}
	void link(int e,int r,int t){
		add(e,r,t);
		add(r,e,0);
	}
	int S,T,dis[M*3],cur[M*3];
	bool bfs(){
		queue<int>q;
		memset(dis,-1,sizeof(dis));
		dis[S]=0;
		q.push(S);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=head[u];i;i=a[i].next){
				if(a[i].dis && dis[a[i].to]==-1){
					dis[a[i].to]=dis[u]+1;
					q.push(a[i].to);
				}
			}
		}
		return (dis[T]!=-1);
	}
	int dfs(int u,int flow){
		if(!flow || u==T)return flow;
		int summ=0;
		for(int &i=head[u];i;i=a[i].next){
			if(a[i].dis && dis[a[i].to]==dis[u]+1){
				int tmp=dfs(a[i].to,min(flow,a[i].dis));
				a[i].dis-=tmp;
				a[i^1].dis+=tmp;
				summ+=tmp;
				flow-=tmp;
				if(!flow)break;
			}
		}
		if(!summ)dis[u]=0;
		return summ;
	}
	int dinic(){
		int summ=0;
		memcpy(cur,head,sizeof(cur));
		while(bfs()){
			summ+=dfs(S,100000000);
			memcpy(head,cur,sizeof(head));
		}
		return summ;
	}
	void main(){
		int tep=dinic();
		tep=-tep;
		for(int k=1;k<=n;k++)if(!kk[k])tep++;
		cout<<tep<<'\n';
//		bfs();
		for(int i=1;i<=n;i++){
			if(dis[i]!=-1 && dis[i+n]==-1){
				cout<<i<<" ";
			}
		}
	}
};
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
//	dbg(1);
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read();
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
		insert(i);
	}
	build();
	for(int i=1;i<=n;i++){
		work(i);
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(g[k][i])g[k]|=g[i];
		}
	}
	L::S=0;L::T=n*2+1;
	for(int i=1;i<=n;i++){
		if(!kk[i])L::link(L::S,i,1);
		L::link(i+n,L::T,1);
		for(int k=1;k<=n;k++){
			if(g[i][k])L::link(i,k+n,1);
		}
	}
	L::main();
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}