#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn],deg[maxn],lft[maxn],rig[maxn],cnt[2],ql;
string s[maxn];
ll ans;
inline int id(int x,int y){return x*m+y+1;}
inline void add(int u,int v){
//	printf("add(%d,%d)\n",u,v);
	to[++el]=v;nxt[el]=head[u];head[u]=el;deg[v]++;
}
void dfs(int u,int tp){
//	printf("dfs(%d,%d)\n",u,tp);
	lft[u]=++cnt[tp];
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs(v,tp);
	}
	rig[u]=cnt[tp];
}
struct ques{
	int x,l,r,w;
	bool operator<(const ques &q)const{return x<q.x;}
}q[maxn];
inline void ins(int l1,int r1,int l2,int r2){
//	printf("ins(%d,%d,%d,%d)\n",l1,r1,l2,r2);
	q[++ql]=(ques){l1,l2,r2,1};
	q[++ql]=(ques){r1+1,l2,r2,-1};
}
int mn[maxn],sum[maxn],tag[maxn];
inline void pushup(int o){
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	sum[o]=0;
	if(mn[o<<1]==mn[o]) sum[o]+=sum[o<<1];
	if(mn[o<<1|1]==mn[o]) sum[o]+=sum[o<<1|1];
}
inline void setadd(int o,int v){
	mn[o]+=v;
	tag[o]+=v;
}
inline void pushdown(int o){
	if(tag[o]){
		setadd(o<<1,tag[o]);
		setadd(o<<1|1,tag[o]);
		tag[o]=0;
	}
}
void build(int o,int l,int r){
	if(l==r) return sum[o]=1,void();
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return setadd(o,v);
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	pushup(o);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,0,n-1) cin>>s[i];
	FOR(i,0,n-1) FOR(j,0,m-1){
		if(s[i][j]=='L' && j!=m-2) add(id(i,j+2),id(i,j));
		if(s[i][j]=='R' && j!=1) add(id(i,j-2),id(i,j));
		if(s[i][j]=='U' && i!=n-2) add(id(i+2,j),id(i,j));
		if(s[i][j]=='D' && i!=1) add(id(i-2,j),id(i,j));
	}
	FOR(i,0,n-1) FOR(j,0,m-1) if(!deg[id(i,j)]) dfs(id(i,j),(i+j)&1);
	FOR(i,0,n-1) FOR(j,0,m-1) if((i+j)&1){
		if(s[i][j]=='L') ins(lft[id(i,j)],rig[id(i,j)],lft[id(i,j+1)],rig[id(i,j+1)]);
		if(s[i][j]=='R') ins(lft[id(i,j)],rig[id(i,j)],lft[id(i,j-1)],rig[id(i,j-1)]);
		if(s[i][j]=='U') ins(lft[id(i,j)],rig[id(i,j)],lft[id(i+1,j)],rig[id(i+1,j)]);
		if(s[i][j]=='D') ins(lft[id(i,j)],rig[id(i,j)],lft[id(i-1,j)],rig[id(i-1,j)]);
	}
	sort(q+1,q+ql+1);
	build(1,1,n*m/2);
	int cur=1;
	FOR(i,1,n*m/2){
		while(cur<=ql && q[cur].x<=i){
			update(1,1,n*m/2,q[cur].l,q[cur].r,q[cur].w);
			cur++;
		}
		ans+=mn[1]?n*m/2:n*m/2-sum[1];
	}
	cout<<ans<<endl;
}