#include<algorithm>
#include<vector>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,m;
char s[maxn];
int cnt=0,head[maxn],nxt[maxn*2],to[maxn*2];
void add_edge(int u,int v){
	cnt++;
	nxt[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int fa[maxn],dep[maxn],size[maxn],hson[maxn];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	hson[u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
}
int pos[maxn],top[maxn];
vector<int> f;
void dfs2(int u){
	pos[u]=f.size();
	f.push_back(u);
	if(!hson[u]) return;
	top[hson[u]]=top[u];
	dfs2(hson[u]);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]||v==hson[u]) continue;
		top[v]=v;
		dfs2(v);
	}
}
namespace SAM{
	int sz,last,len[maxn*4],link[maxn*4],nxt[maxn*4][26];
	vector<int> ch[maxn*4];
	void init(){
		sz=1;
		last=0;
		len[0]=0;
		link[0]=-1;
	}
	void extend(int c){
		int cur=sz++;
		len[cur]=len[last]+1;
		int p=last;
		while(p>=0&&!nxt[p][c]){
			nxt[p][c]=cur;
			p=link[p];
		}
		if(p<0) link[cur]=0;
		else{
			int q=nxt[p][c];
			if(len[p]+1==len[q]) link[cur]=q;
			else{
				int clone=sz++;
				len[clone]=len[p]+1;
				link[clone]=link[q];
				memcpy(nxt[clone],nxt[q],sizeof(nxt[q]));
				while(p>=0&&nxt[p][c]==q){
					nxt[p][c]=clone;
					p=link[p];
				}
				link[q]=link[cur]=clone;
			}
		}
		last=cur;
	}
	int cur[maxn*2];
	int dep[maxn*4],pos[maxn*4];
	vector<int> f;
	void dfs(int u){
		pos[u]=f.size();
		f.push_back(u);
		dep[u]=u?dep[link[u]]+1:1;
		for(int i=0;i<(int)ch[u].size();i++){
			int v=ch[u][i];
			dfs(v);
			f.push_back(u);
		}
	}
	int st[25][maxn*8],lg[maxn*8];
	void build_st(){
		for(int i=0;i<sz*2-1;i++) st[0][i]=i;
		for(int i=1;(1<<i)-1<sz*2-1;i++)
			for(int j=0;j+(1<<i)-1<sz*2-1;j++)
				if(dep[f[st[i-1][j]]]<dep[f[st[i-1][j+(1<<(i-1))]]])
					st[i][j]=st[i-1][j];
				else st[i][j]=st[i-1][j+(1<<(i-1))];
		for(int i=2;i<=sz*2-1;i++) lg[i]=lg[i/2]+1;
	}
	int rmq_query(int l,int r){
		int k=lg[r-l+1];
		if(dep[f[st[k][l]]]<dep[f[st[k][r-(1<<k)+1]]]) return st[k][l];
		else return  st[k][r-(1<<k)+1];
	}
	int lca(int x,int y){
		if(pos[x]<pos[y]) return f[rmq_query(pos[x],pos[y])];
		else return f[rmq_query(pos[y],pos[x])];
	}
	int lcs(int x,int y){
		return len[lca(cur[x],cur[y])];
	}
}
using SAM::sz;
using SAM::last;
using SAM::link;
using SAM::ch;
using SAM::init;
using SAM::extend;
using SAM::cur;
using SAM::dfs;
using SAM::build_st;
using SAM::lcs;
typedef pair<int,int> pii;
void get(int x,int y,vector<pii>& s){
	vector<pii> res;
	while(top[x]!=top[y])
		if(dep[top[x]]<dep[top[y]]){
			s.push_back(pii(n*2-pos[y]-1,n*2-pos[top[y]]-1));
			y=fa[top[y]];
		}
		else{
			res.push_back(pii(pos[top[x]],pos[x]));
			x=fa[top[x]];
		}
	if(dep[x]<dep[y]) s.push_back(pii(n*2-pos[y]-1,n*2-pos[x]-1));
	else res.push_back(pii(pos[y],pos[x]));
	for(int i=(int)res.size()-1;i>=0;i--) s.push_back(res[i]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	scanf("%s",s+1);
	for(int i=1;i<n;i++){
		int u,v;
		u=readint();
		v=readint();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	init();
	for(int i=0;i<n;i++){
		extend(s[f[i]]-'a');
		cur[i]=last;
	}
	for(int i=0;i<n;i++){
		extend(s[f[n-i-1]]-'a');
		cur[i+n]=last;
	}
	for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
	dfs(0);
	build_st();
	m=readint();
	while(m--){
		int a,b,c,d;
		a=readint();
		b=readint();
		c=readint();
		d=readint();
		vector<pii> s1,s2;
		get(a,b,s1);
		get(c,d,s2);
		int ans=0;
		while(!s1.empty()&&!s2.empty()){
			int l1=s1.back().first,r1=s1.back().second;
			s1.pop_back();
			int l2=s2.back().first,r2=s2.back().second;
			s2.pop_back();
			int l=min(lcs(r1,r2),min(r1-l1+1,r2-l2+1));
			if(!l) break;
			ans+=l;
			if(l<r1-l1+1) s1.push_back(pii(l1,r1-l));
			if(l<r2-l2+1) s2.push_back(pii(l2,r2-l));
		}
		printf("%d\n",ans);
	}
	return 0;
}