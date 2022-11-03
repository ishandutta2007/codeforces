#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int c[400010],FA[400010];
ll SUM,ans[400010];
int fa[400010],ch[400010][2],siz[400010],_siz[400010],cnt;
ll _siz2[400010];
il ll sqr(int x){return 1ll*x*x;}
bool rev[400010];
std::vector<std::pair<int,int>>G[400010];
int qu[400010],qx[400010];
namespace tree{
	int fir[400010],dis[800010],nxt[800010],id;
	il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
	il vd dfs(int x){
		for(int i=fir[x];i;i=nxt[i]){
			if(FA[x]==dis[i])continue;
			FA[dis[i]]=x;dfs(dis[i]);
		}
	}
}
il bool isrt(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
il vd upd(int x){if(x)siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+_siz[x]+1;}
il vd Rev(int x){if(x)rev[x]^=1,std::swap(ch[x][0],ch[x][1]);}
il vd down(int x){
	if(!x)return;
	if(!isrt(x))down(fa[x]);
	if(rev[x])Rev(ch[x][0]),Rev(ch[x][1]),rev[x]=0;
}
il vd rotate(int x){
	int y=fa[x],z=fa[y],o=x==ch[y][1];
	if(!isrt(y))ch[z][y==ch[z][1]]=x;fa[x]=z;
	ch[y][o]=ch[x][!o];fa[ch[x][!o]]=y;
	ch[x][!o]=y;fa[y]=x;
	upd(y);
}
il vd splay(int x){
	if(!x)return;
	down(x);int y,z;
	while(!isrt(x)){
		y=fa[x],z=fa[y];
		if(!isrt(y))rotate(((ch[y][0]==x)^(ch[z][0]==y))?x:y);
		rotate(x);
	}
	upd(x);
}
il vd access(int x){for(int y=0;x;x=fa[y=x])splay(x),_siz[x]+=siz[ch[x][1]]-siz[y],_siz2[x]+=sqr(siz[ch[x][1]])-sqr(siz[y]),ch[x][1]=y,upd(x);}
il int find(int x){access(x),splay(x);while(ch[x][0])x=ch[x][0];splay(x);return x;}
il vd makert(int x){splay(x);access(x);rev[x]^=1;}
il vd link(int x,int y){//y==FA[x]
	splay(x);SUM-=sqr(siz[ch[x][1]])+_siz2[x];
	int z=find(y);
	access(x);splay(z);SUM-=sqr(siz[ch[z][1]]);
	splay(y);fa[x]=y;_siz[y]+=siz[x];_siz2[y]+=sqr(siz[x]);
	upd(y);
	access(x);splay(z);SUM+=sqr(siz[ch[z][1]]);
}
il vd cut(int x,int y){
	access(x);SUM+=_siz2[x];
	int z=find(y);
	access(x);splay(z);SUM-=sqr(siz[ch[z][1]]);
	splay(y);splay(x);
	ch[x][0]=fa[y]=0;upd(x);
	splay(z);SUM+=sqr(siz[ch[z][1]]);
}
bool nowcol[400010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=n;++i)c[i]=gi();
	for(int i=1;i<n;++i)a=gi(),b=gi(),tree::link(a,b),tree::link(b,a);
	tree::dfs(1);
	FA[1]=n+1;
	for(int i=1;i<=n;++i)siz[i]=1;
	for(int i=1;i<=n;++i)link(i,FA[i]);
	for(int i=1;i<=n;++i)G[c[i]].push_back({i,0});
	for(int i=1;i<=m;++i){
		qu[i]=gi(),qx[i]=gi();
		G[c[qu[i]]].push_back({qu[i],i});
		G[c[qu[i]]=qx[i]].push_back({qu[i],i});
	}
	for(int i=1;i<=n;++i){
		ll lst=0;
		for(auto j:G[i]){
			int x=j.first,t=j.second;
			if(nowcol[x])nowcol[x]=0,link(x,FA[x]);
			else nowcol[x]=1,cut(x,FA[x]);
			ans[t]+=1ll*n*n-SUM-lst;
			lst=1ll*n*n-SUM;
		}
		for(auto j:G[i])if(nowcol[j.first])nowcol[j.first]=0,link(j.first,FA[j.first]);
	}
	for(int i=1;i<=m;++i)ans[i]+=ans[i-1];
	for(int i=0;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}