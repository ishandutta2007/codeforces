#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],el,head[maxn],to[maxn],nxt[maxn],fa[maxn];
int sz[maxn],dep[maxn],dfn[maxn],at[maxn],cnt,scnt,rt,m,ans[maxn];
int p[maxn],seq[maxn],sl,ql,bit[maxn],lst[maxn];
bool isrt[maxn];
map<string,int> id;
struct ques{
	int u,k,id;
	bool operator<(const ques &q)const{
		return dep[u]+k<dep[q.u]+q.k;
	}
}q[maxn];
struct quess{
	int l,r,id;
	bool operator<(const quess &q)const{
		return r<q.r;
	}
}qq[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline bool cmp(int x,int y){
	if(dep[x]!=dep[y]) return dep[x]<dep[y];
	return dfn[x]<dfn[y];
}
void dfs(int u){
	dfn[u]=++cnt;
	at[cnt]=u;
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs(v);
		sz[u]+=sz[v];
	}
}
inline void update(int p,int v){
	for(int i=p;i<=sl;i+=i&-i) bit[i]+=v;
}
inline int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s+=bit[i];
	return s;
}
inline int query(int l,int r){
	return query(r)-query(l-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	FOR(i,1,n){
		string s;
		int f;
		cin>>s>>f;
		if(!id[s]) id[s]=++scnt;
		a[i]=id[s];
		if(f) add(fa[i]=f,i);
		else isrt[i]=true;
	}
	FOR(i,1,n) if(isrt[i]) dfs(i);
	cin>>m;
	FOR(i,1,m){
		int u,k;
		cin>>u>>k;
		q[i]=(ques){u,k,i};
	}
	sort(q+1,q+m+1);
	FOR(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	int cur1=1,cur2=1;
	FOR(i,1,n){
		sl=0;
		while(cur1<=n && dep[p[cur1]]==i){
			seq[++sl]=dfn[p[cur1]];
			cur1++;
		}
		ql=0;
		while(cur2<=m && dep[q[cur2].u]+q[cur2].k==i){
			int l=lower_bound(seq+1,seq+sl+1,dfn[q[cur2].u])-seq;
			int r=lower_bound(seq+1,seq+sl+1,dfn[q[cur2].u]+sz[q[cur2].u]-1)-seq;
			if(r>sl || seq[r]>dfn[q[cur2].u]+sz[q[cur2].u]-1) r--;
			if(l<=r) qq[++ql]=(quess){l,r,q[cur2].id};
			cur2++;
		}
		sort(qq+1,qq+ql+1);
		int cur3=1;
		FOR(j,1,ql){
			while(cur3<=qq[j].r){
				update(cur3,1);
				if(lst[a[at[seq[cur3]]]]) update(lst[a[at[seq[cur3]]]],-1);
				lst[a[at[seq[cur3]]]]=cur3;
				cur3++;
			}
			ans[qq[j].id]=query(qq[j].l,qq[j].r);
		}
		FOR(j,1,sl) bit[j]=lst[a[at[seq[j]]]]=0;
	}
	FOR(i,1,m) printf("%d\n",ans[i]);
}