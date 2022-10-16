#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100,mod=998244353;
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
struct ques{
	int r,k,id,w;
	bool operator<(const ques &q)const{return r<q.r;}
}qu[maxn];
int n,Q,tot,ch[maxn][26],at[maxn],fail[maxn],fa[maxn],q[maxn],h,r,el,head[maxn],to[maxn],nxt[maxn],lft[maxn],rig[maxn],dfn;
ll ans[maxn],b[maxn];
char s[maxn];
inline void add(int u,int v){ 
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline void update(int p,ll v){
	for(int i=p;i<=tot+1;i+=i&-i) b[i]+=v;
}
inline ll query(int p){
	ll s=0;
	for(int i=p;i;i-=i&-i) s+=b[i];
	return s;
}
inline ll query(int l,int r){
	return query(r)-query(l-1);
}
void insert(char *s,int id){
	int l=strlen(s+1),now=0;
	FOR(i,1,l){
		int p=s[i]-'a';
		if(!ch[now][p]) ch[now][p]=++tot,fa[tot]=now;
		now=ch[now][p];
	}
	at[id]=now;
}
void build(){
	h=1;r=0;
	FOR(i,0,25) if(ch[0][i]) q[++r]=ch[0][i];
	while(h<=r){
		int u=q[h++];
		FOR(i,0,25) if(ch[u][i]){
			fail[ch[u][i]]=ch[fail[u]][i];
			q[++r]=ch[u][i];
		}
		else ch[u][i]=ch[fail[u]][i];
	}
}
void dfs(int u){
	lft[u]=++dfn;
	for(int i=head[u];i;i=nxt[i]) dfs(to[i]); 
	rig[u]=dfn;
}
int main(){
	n=read();Q=read();
	FOR(i,1,n){
		scanf("%s",s+1);
		insert(s,i);
	}
	build();
	FOR(i,1,tot) add(fail[i],i);
	dfs(0);
	FOR(i,1,Q){
		int l=read(),r=read(),k=read();
		qu[2*i-1]=(ques){l-1,k,i,-1};
		qu[2*i]=(ques){r,k,i,1};
	}
	sort(qu+1,qu+2*Q+1);
	int cur=1; 
	FOR(i,1,2*Q){
		while(cur<=qu[i].r){
			for(int u=at[cur];u;u=fa[u]) update(lft[u],1);
			cur++;
		}
		ans[qu[i].id]+=qu[i].w*query(lft[at[qu[i].k]],rig[at[qu[i].k]]);
	}
	FOR(i,1,Q) printf("%lld\n",ans[i]);
}