#include<bits/stdc++.h>
#define ll long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,q;
V<P<int,int> > p[400005][26];
V<int> v[400005];
int dep[400005],fa[400005]; 
void dfs(int x,int y){
	for(auto u:v[x])if(u!=y){
		dep[u]=dep[x]+1;
		fa[u]=x;
		dfs(u,x);
	}
}
char c[400005];
P<int,int> ed[400005];
V<int> g[2500005];
int cnt,dfn[2500005],low[2500005];
int ta,cntcol,col[2500005],in[2500005],it[11000000];
V<int> node;
void dfs2(int x){
	node.PB(x);dfn[x]=low[x]=++cnt;
	in[x]=1;
	for(auto u:g[x]){
		if(dfn[u]){
			if(in[u])gmin(low[x],dfn[u]);
		}else{
			dfs2(u);
			gmin(low[x],low[u]);
		}
	}
	if(dfn[x]==low[x]){
		++cntcol;
		while(node.back()!=x){
			in[node.back()]=0;
			col[node.back()]=cntcol;
			node.pop_back();
		}
		in[x]=0;col[x]=cntcol;
		node.pop_back();
	}
}
void add(int a,int va,int b,int vb){
	g[a+ta*(va&1)].PB(b+ta*(vb^1));
	g[b+ta*(vb&1)].PB(a+ta*(va^1));
}
char ans[400005];
void add(int x,int y){
	g[x].PB(y);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	ta=800000+q;
	int pos=0;
	FOR(i,1,q){
		int x,y;
		string s;
		cin>>x>>y>>s;
		ed[i]=MP(x,y);
		int len=s.size();
		FOR(j,1,len)c[j]=s[j-1];
		int tx=x,ty=y,tl=1,tr=len;
		while(x!=y){
			if(dep[x]>=dep[y]){
				p[x][c[tl]-'a'].PB(MP(i,0));
				tl++;x=fa[x];
			}else{
				p[y][c[tr]-'a'].PB(MP(i,0));
				tr--;y=fa[y];
			}
		}
		p[x][c[tl]-'a'].PB(i,0);
		x=ty;y=tx;
		tl=1,tr=len;
		while(x!=y){
			if(dep[x]>=dep[y]){
				p[x][c[tl]-'a'].PB(MP(i,1));
				tl++;x=fa[x];
			}else{
				p[y][c[tr]-'a'].PB(MP(i,1));
				tr--;y=fa[y];
			}
		}
		p[x][c[tl]-'a'].PB(i,1);
	}
	FOR(i,1,n)FOR(j,0,25)if(!p[i][j].empty())it[(i-1)*26+j+1]=++pos;
	FOR(i,1,n){
		FOR(j,0,25)if(!p[i][j].empty()){
			for(auto u:p[i][j]){
				add(u.F+800000,!u.S,it[(i-1)*26+j+1],1);
			}
		}
		FOR(j,0,25)FOR(k,j+1,25)if(!p[i][j].empty()&&!p[i][k].empty()){
			add(it[(i-1)*26+j+1],0,it[(i-1)*26+k+1],0);
		}
	}
	FOR(i,1,ta*2)if(!dfn[i])dfs2(i);
	FOR(i,1,ta)if(col[i]==col[i+ta]){
		cout<<"NO";RE 0;
	}
	cout<<"YES\n";
	FOR(i,1,n){
		ans[i]='a';
		rep(j,0,26)if(!p[i][j].empty()&&col[it[(i-1)*26+j+1]]<col[it[(i-1)*26+j+1]+ta]){
			ans[i]=j+'a';break;
		}
		cout<<ans[i];
	}
	RE 0;
}