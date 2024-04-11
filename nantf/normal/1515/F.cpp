#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int maxn=666666,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,m,x,el,head[maxn],tail[maxn],to[maxn],nxt[maxn],w[maxn],fa[maxn],ans[maxn],al;
ll a[maxn];
set<PII> s;
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
	if(!tail[u]) tail[u]=el;
}
inline int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	n=read();m=read();x=read();
	FOR(i,1,n) a[i]=read()-x;
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v,i);add(v,u,i);
	}
	FOR(i,1,n) fa[i]=i,s.insert(MP(a[i],i));
	while((int)s.size()!=1){
		auto it=--s.end();
		int u=it->second;
//		printf("u=%d,a[%d]=%lld,head[%d]=%d\n",u,u,a[u],u,head[u]);
		if(a[u]<0) break;
		s.erase(it);
		for(int &i=head[u];i;){
			int v=getfa(to[i]);
//			printf("try edge %d %d\n",i,w[i]);
			if(v==u){i=nxt[i];continue;}
//			printf("v=%d,add edge %d,head[%d]=%d\n",v,w[i],v,head[v]);
			s.erase(MP(a[v],v));
			a[u]+=a[v];
			fa[v]=u;
			ans[++al]=w[i];
			if(head[v]) nxt[tail[v]]=head[u],head[u]=head[v];
			else i=nxt[i];
//			puts("done");
			if(a[u]<0) break;
		}
//		puts("over");
		s.insert(MP(a[u],u));
	}
	ll sum=0;
	for(auto it=s.begin();it!=s.end();it++) sum+=it->first;//,printf("add %lld %d\n",it->first,it->second);
	if(sum<-x) return puts("NO"),0;
	while((int)s.size()!=1){
		auto it=--s.end();
		int u=it->second;
		s.erase(it);
		for(int &i=head[u];i;){
			int v=getfa(to[i]);
			if(v==u){i=nxt[i];continue;}
			s.erase(MP(a[v],v));
			a[u]+=a[v];
			fa[v]=u;
			ans[++al]=w[i];
			if(head[v]) nxt[tail[v]]=head[u],head[u]=head[v];
			else i=nxt[i];
		}
		s.insert(MP(a[u],u));
	}
	puts("YES");
	FOR(i,1,n-1) printf("%d\n",ans[i]);
}