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
int n,cnt,lst,fa[maxn],ch[maxn][26],len[maxn],el,head[maxn],to[maxn],nxt[maxn],rt[maxn],tot,ls[maxn*33],rs[maxn*33],ans,pos[maxn],f[maxn],tr[maxn];
char s[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline void init(){
	fa[0]=-1;
}
void update(int &x,int l,int r,int p){
	if(!x) x=++tot;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=p) update(ls[x],l,mid,p);
	else update(rs[x],mid+1,r,p);
}
int merge(int x,int y){
	if(!x || !y) return x+y;
	int now=++tot;
	ls[now]=merge(ls[x],ls[y]);
	rs[now]=merge(rs[x],rs[y]);
	return now;
}
bool query(int x,int l,int r,int ql,int qr){
	if(!x) return false;
	if(l>=ql && r<=qr) return true;
	int mid=(l+r)>>1;
	if(mid<ql) return query(rs[x],mid+1,r,ql,qr);
	if(mid>=qr) return query(ls[x],l,mid,ql,qr);
	return query(ls[x],l,mid,ql,qr) || query(rs[x],mid+1,r,ql,qr);
}
void extend(int id,int c){
	int now=++cnt;
	pos[now]=id;
	len[now]=len[lst]+1;
	int p=lst;
	lst=now;
	for(;~p && !ch[p][c];p=fa[p]) ch[p][c]=now;
	if(~p){
		int q=ch[p][c];
		if(len[p]+1==len[q]) fa[now]=q;
		else{
			int cl=++cnt;
			len[cl]=len[p]+1;
			fa[cl]=fa[q];
			pos[cl]=pos[q];
			fa[q]=fa[now]=cl;
			FOR(i,0,25) ch[cl][i]=ch[q][i];
			for(;~p && ch[p][c]==q;p=fa[p]) ch[p][c]=cl;
		}
	}
}
void dfs(int u){
	update(rt[u],1,n,pos[u]);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs(v);
		rt[u]=merge(rt[u],rt[v]);
	}
}
void dfs2(int u){
	if(u){
		if(!fa[u]) tr[u]=u,f[u]=1;
		else{
			int tmp=tr[fa[u]];
			if(query(rt[tmp],1,n,pos[u]-len[u]+len[tmp],pos[u]-1)) tr[u]=u,f[u]=f[fa[u]]+1;//,printf("%d from %d\n",u,tr[fa[u]]);
			else tr[u]=tmp,f[u]=f[fa[u]];
		}
	}
	ans=max(ans,f[u]);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs2(v);
	}
}
int main(){
	n=read();
	scanf("%s",s+1);
	init();
	FOR(i,1,n) extend(i,s[i]-'a');
	FOR(i,1,cnt) add(fa[i],i);
	dfs(0);
	dfs2(0);
	printf("%d\n",ans);
}