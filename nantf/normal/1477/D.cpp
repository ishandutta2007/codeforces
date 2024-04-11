#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
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
int n,m,deg[maxn],p[maxn],q[maxn],rem,que[maxn],h,r,el,head[maxn],to[maxn],nxt[maxn];
bool in[maxn];
set<PII,greater<PII> > s;
set<int> nvis,e[maxn];
inline void add(int u,int v){
	e[u].insert(v);
}
inline void add2(int u,int v){
//	printf("add(%d,%d)\n",u,v);
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void clear(){
	FOR(i,1,n) deg[i]=p[i]=q[i]=head[i]=in[i]=0;
	s.clear();
	nvis.clear();
	FOR(i,1,n) e[i].clear();
	FOR(i,1,el) to[i]=nxt[i]=0;
	el=0;
}
bool dfs(int u,int f){
	int son=0,cnt=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(dfs(v,u)) cnt++;
		else son=v;
	}
//	printf("u=%d,cnt=%d\n",u,cnt);
	if(cnt){
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(!in[v]) continue;
			p[v]=rem;
			q[v]=--rem;
		}
		q[u]=rem+cnt;
		p[u]=rem--;
		return in[u]=false;
	}
	else if(!f){
		assert(son);
//		puts("in");
		p[u]=q[u]=rem--;
		swap(p[u],p[son]);
		return in[u]=false;
	}
	else return in[u]=true;
}
void bfs(int s){
	que[h=r=1]=s;
	while(h<=r){
		int u=que[h++];
		for(set<int>::iterator it=nvis.begin();it!=nvis.end();){
			int v=*it;
//			printf("try %d to %d\n",u,v);
			if(e[u].find(v)!=e[u].end()){it++;continue;}
			set<int>::iterator it1=it++;
			nvis.erase(it1);
			que[++r]=v;
			add2(u,v);
		}
	}
	dfs(s,0);
/*	set<int>::iterator it=nvis.begin();
	int son=0;
	if(!vec[u].empty()){
		p[u]=rem;
		FOR(i,0,(int)vec[u].size()-1) p[vec[u][i]]=rem-i-1;
		FOR(i,0,(int)vec[u].size()-1) q[vec[u][i]]=rem-i;
		q[u]=rem-=vec[u].size();
		return false;
	}
	else if(rt){
		assert(son);
		p[u]=q[u]=rem--;
		swap(q[u],q[son]);
		return false;
	}
	else return true;*/
}
void solve(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
		deg[u]++;deg[v]++;
	}
	FOR(i,1,n) s.insert(MP(deg[i],i));
	rem=n;
	while(!s.empty() && s.begin()->first==(int)s.size()-1){
		int u=s.begin()->second;
		s.erase(s.begin());
//		printf("erase %d\n",u);
		p[u]=q[u]=rem--;
		for(set<int>::iterator it=e[u].begin();it!=e[u].end();it++){
			int v=*it;
			s.erase(MP(deg[v],v));
			s.insert(MP(--deg[v],v));
			e[v].erase(u);
		}
		e[u].clear();
		deg[u]=0;
	}
	FOR(i,1,n) if(!p[i]) nvis.insert(i);
	FOR(i,1,n) if(!p[i]){
		nvis.erase(i);
		bfs(i);
	}
	FOR(i,1,n) printf("%d ",p[i]);
	puts("");
	FOR(i,1,n) printf("%d ",q[i]);
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}