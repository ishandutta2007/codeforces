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
const int N=2e5+5;
int n,m,summ,tot,zs,ans,el;
int x[N],y[N],z[N],siz[N],g[N];
bool vis[N];
set<int>s;
map<pii,int>ma;
vi v[N];
int f[N];
struct node{
	int x,y,z,xx,yy;
}a[N];
int cmp(node x,node y){
	return x.z<y.z;
}
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	f[y]=x;siz[x]+=siz[y];
}
void work(int u){
	queue<int>q;
	q.push(u);
	int tmp=0;vis[u]=1;
	s.erase(u);
	while(!q.empty()){
		int u=q.front();q.pop();
		tmp++;
		for(auto it=s.begin();it!=s.end();){
			int vv=*it++;
			if(!ma[mp(u,vv)]){
				vis[vv]=1;
				q.push(vv);
				s.erase(vv);
				merge(u,vv);
				v[u].pb(vv);
				v[vv].pb(u);
			}
		}
	}
	zs+=(tmp-1);
}
int fu[N],deep[N],pd[N];
void dfs(int u,int fa){
	fu[u]=fa;deep[u]=deep[fa]+1;
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs(i,u);
	}
}
bool check(int x,int y){
	while(x!=y){
		if(deep[x]<deep[y])swap(x,y);
		if(find(x)==find(fu[x]))return 1;
		x=fu[x];
	}
	return 0;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();summ=n*(n-1)/2-m;
	for(int i=1;i<=m;i++){
		x[i]=read();y[i]=read();z[i]=read();
		ma[mp(x[i],y[i])]=ma[mp(y[i],x[i])]=1;
		el^=z[i];
	}
	for(int i=1;i<=n;i++)s.insert(i),f[i]=i,siz[i]=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			work(i);tot++;
		}
	}
	for(int i=1;i<=m;i++){
		a[i].x=find(x[i]);
		a[i].y=find(y[i]);
		a[i].z=z[i];
		a[i].xx=x[i];
		a[i].yy=y[i];
	}
	sort(a+1,a+m+1,cmp);
	memcpy(g,f,sizeof(g));
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			ans+=a[i].z;
			merge(a[i].x,a[i].y);
		//	cout<<a[i].x<<" "<<a[i].y<<'\n';
			v[a[i].xx].pb(a[i].yy);
			v[a[i].yy].pb(a[i].xx);
			pd[i]=1;
		}
	}
	memcpy(f,g,sizeof(g));
	if(summ>zs){
		cout<<ans;
		return 0;
	}
	else{
		int tmp=ans+el;
		dfs(1,0);
		for(int i=1;i<=m;i++){
			if(a[i].xx==4 && a[i].yy==6){
				new char;
			}
			if(check(a[i].xx,a[i].yy) && !pd[i]){
				tmp=min(tmp,ans+a[i].z);
			}
		}
		cout<<tmp;
	}
	return 0;
}