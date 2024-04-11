#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cassert>
#include<unordered_map>
//#include<ctime>
using namespace std;
//#define int long long
const int N=2002020;
typedef pair<int,int> PII;
typedef long long ll;
#define mkpr make_pair
int n,m,k,tot,tot1,sum,cnt,T,Iid,top1; bool nt[N],vs[N],fl; ll ans;
int v[N],v1[N],c[N],bl[N],id[N][2],col[N],vis[N],siz[N],d[N],stk[N],stk1[N];
int cc[N];
unordered_map<ll,int> mp,mp2; vector<PII> q[N];
struct Edge{int to,next;}e[N<<1];
struct Edge1{int to,next;}e1[N<<1];
struct Edgeb{int x,y;}b[N];
inline void add_edge(int x,int y){
	e[++tot].to=y; e[tot].next=v[x]; v[x]=tot;
}
inline void add_edge1(int x,int y){
	e1[++tot1].to=y; e1[tot1].next=v1[x]; v1[x]=tot1;
}
inline void add(int x,int y){
	add_edge(x,y); add_edge(y,x);
//	cout<<"add "<<x<<" "<<y<<endl;
}
inline void add1(int x,int y){
	add_edge1(x,y); add_edge1(y,x);
}
inline void Add(int idt){
//	cout<<"Add "<<idt<<endl;
	for(int i=0;i<q[idt].size();i++)
		add(q[idt][i].first,q[idt][i].second);//,cout<<"add "<<q[idt][i].first<<" "<<q[idt][i].second<<endl;
}
inline ll get1(int x,int y){
	if(x>y)swap(x,y);
	return 1ll*(x-1)*(n+k)+y;
}
bool dfs(int x){
	int cl=0; vis[x]=T;
	int top; stk[top=1]=x;
	for(int i=1;i<=top;i++){
		int w=stk[i];
		for(int p=v[w];p;p=e[p].next){
			int kp=e[p].to;
			if(vis[kp]!=T)col[stk[++top]=kp]=col[w]^1,vis[kp]=T;
			else if(col[kp]==col[w])return 1;
		}
	} return 0;
}
inline int oddcir(){
	fl=0; ++T;
	for(int i=1;i<=top1;i++)
		if(vis[stk1[i]]!=T){
			if(dfs(stk1[i]))return 1;
		}
	return 0;
}
void dfs1(int x){
	int top; stk[top=1]=x; vis[x]=T;
	for(int i=1;i<=top;i++){
		int w=stk[i]; bl[w]=sum; ++siz[sum];
		for(int p=v[w];p;p=e[p].next){
			int kp=e[p].to;
			if(c[kp]!=c[x])continue;
			if(vis[kp]!=T)vis[kp]=T,col[stk[++top]=kp]=col[w]^1;
			else if(col[w]==col[kp])fl=1;
		}
	}
}
inline bool check(int x){
	fl=0; ++T; d[++sum]=c[x]; dfs1(x); return fl;
}
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline int get(ll x){
	if(!mp2[x])mp2[x]=++Iid; return mp2[x];
}
void dfs2(int x){
	stk1[++top1]=x; vs[x]=1;
	for(int p=v1[x];p;p=e1[p].next)
		if(!vs[e1[p].to])add(e1[p].to,x),dfs2(e1[p].to);
}
void getuse(int x,int y){
	if(!vs[x])dfs2(x);
	if(!vs[y])dfs2(y);
}
//#undef int
int main()
{
//	freopen("data.in","r",stdin);
//	#define int long long
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=m;i++)
		b[i].x=read(),b[i].y=read(),add(b[i].x,b[i].y);
//	cout<<endl;
	for(int i=1;i<=n;i++)
		if(!bl[i] && !nt[c[i]])nt[c[i]]=check(i);
	for(int i=1;i<=k;i++)
		if(!nt[i])++ans;
	ans=1ll*ans*(ans-1)/2;
	for(int i=1;i<=sum;i++){
		if(nt[d[i]])continue;
		id[i][0]=++cnt;//,p[d[i]].push_back(cnt);
		if(siz[i]>1)id[i][1]=++cnt;//,p[d[i]].push_back(cnt);
	}
	for(int i=1;i<=n;i++)v[i]=0; tot=0;
	for(int i=1;i<=m;i++){
		int x=b[i].x,y=b[i].y;
		if(nt[c[x]] || nt[c[y]])continue;
		int fr=id[bl[x]][col[x]],to=id[bl[y]][col[y]];
		if(fr!=to)q[get(get1(c[x],c[y]))].push_back(mkpr(fr,to));
		if(c[x]==c[y] && fr!=to && !cc[fr])add1(fr,to),cc[fr]=cc[to]=1;
	}
	for(int i=1;i<=m;i++){
		int x=b[i].x,y=b[i].y;
		if(nt[c[x]] || nt[c[y]] || c[x]==c[y])continue;
		if(!mp[get1(c[x],c[y])]){
			top1=0; int idt=mp2[get1(c[x],c[y])];
			for(int j=0;j<q[idt].size();j++){
				int x1=q[idt][j].first,x2=q[idt][j].second;
				getuse(x1,x2); add(x1,x2);
			}
			if(oddcir())--ans;
			mp[get1(c[x],c[y])]=1;
			for(int j=1;j<=top1;j++)v[stk1[j]]=0,vs[stk1[j]]=0; tot=0;
		}

	} cout<<ans<<endl;
	return 0;
}