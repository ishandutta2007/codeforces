#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
int n,el,head[maxn],to[maxn],nxt[maxn],w[maxn],sz[maxn],son[maxn],rt,id[maxn],tot[maxn],ans1[maxn],ans2[maxn];
set<int> s[maxn],res;
set<PII> s2,s3;
ll dis[maxn],ans;
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
void dfs(int u,int f){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		son[u]=max(son[u],sz[v]);
	}
	son[u]=max(son[u],n-sz[u]);
	if(!rt || son[u]<son[rt]) rt=u;
}
void dfs2(int u,int f,int at){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dis[v]=dis[u]+w[i];
		dfs2(v,u,at?at:v);
	}
	ans+=dis[u]*2;
	id[u]=at?at:u;
	s[id[u]].insert(u);
	tot[id[u]]+=2;
}
inline void work(int id){
	s2.erase(MP(tot[id],id));
	tot[id]--;
	if(tot[id]) s2.insert(MP(tot[id],id));
}
void doit(int *ans,int tp){
	dfs2(rt,0,0);
	if(!tp){
		s2.insert(MP(tot[rt],rt));
		s3.insert(MP(*s[rt].begin(),rt));
	}
	for(int i=head[rt];i;i=nxt[i]){
		int v=to[i];
		s2.insert(MP(tot[v],v));
		s3.insert(MP(*s[v].begin(),v));
	}
	FOR(i,1,n) if(!tp || i!=rt) res.insert(i);
	FOR(i,1,n){
		if(tp && i==rt) continue;
		int u=0,lst=s2.rbegin()->second;
		if(tot[lst]==n-(tp && i<=rt)-i+1 && id[i]!=lst) u=*s[lst].begin();
		else{
			int at=s3.begin()->second;
			if(id[i]==at) at=(++s3.begin())->second;
			u=*s[at].begin();
		}
		ans[i]=u;
		res.erase(u);
		work(id[i]);
		s3.erase(MP(*s[id[u]].begin(),id[u]));
		s[id[u]].erase(u);
		if(!s[id[u]].empty()) s3.insert(MP(*s[id[u]].begin(),id[u]));
		work(id[u]);
	}
}
void clear(){
	FOR(i,1,n) s[i].clear();
	res.clear();s2.clear();s3.clear();
	FOR(i,1,n) tot[i]=0;
}
int main(){
//	freopen("sumdis.in","r",stdin);
//	freopen("sumdis.out","w",stdout);
	n=read();
	if(n==1) return puts("0\n1"),0;
	FOR(i,1,n-1){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	dfs(1,0);
	dfs2(rt,0,0);
	printf("%lld\n",ans);
	clear();
	MEM(ans1,0x3f);MEM(ans2,0x3f);
	doit(ans1,0);
	if(son[rt]*2<n){
		clear();
		doit(ans2,1);
		ans2[rt]=rt;
	}
	FOR(i,1,n) if(ans1[i]<ans2[i]) break;
	else if(ans1[i]>ans2[i]){swap(ans1,ans2);break;}
	FOR(i,1,n) printf("%d ",ans1[i]);
}
/*
6 2
3 1 1
3 2 1
3 4 1
3 5 1
3 6 1
*/