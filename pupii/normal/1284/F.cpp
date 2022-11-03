#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[250010],dis[500010],nxt[500010],id;
void Link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int fa[500010],ch[500010][2];
bool rev[500010],yes[500010],YES[500010];
bool isrt(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
void upd(int x){if(x)YES[x]=yes[x]&YES[ch[x][0]]&YES[ch[x][1]];}
void Rev(int x){if(x)std::swap(ch[x][0],ch[x][1]),rev[x]^=1;}
void down(int x,bool up=1){
	if(!x)return;
	if(up&&!isrt(x))down(fa[x],1);
	if(rev[x])Rev(ch[x][0]),Rev(ch[x][1]),rev[x]=0;
}
void rotate(int x){
	int y=fa[x],z=fa[y],o=ch[y][1]==x;
	fa[x]=z;if(!isrt(y))ch[z][y==ch[z][1]]=x;
	ch[y][o]=ch[x][!o];fa[ch[x][!o]]=y;
	fa[y]=x;ch[x][!o]=y;
	upd(y);
}
void splay(int x){
	if(!x)return;
	down(x);
	int y,z;
	while(!isrt(x)){
		y=fa[x],z=fa[y];
		if(!isrt(y))rotate(((x==ch[y][0])^(y==ch[z][0]))?x:y);
		rotate(x);
	}
	upd(x);
}
void access(int x){for(int y=0;x;x=fa[y=x])splay(x),ch[x][1]=y,upd(x);}
void makert(int x){access(x),splay(x),Rev(x);}
void link(int x,int y){makert(x),fa[x]=y;}
bool cut(int x,int y){
	makert(x),access(y),splay(y);
	if(fa[x]==y&&ch[y][0]==x&&!ch[x][0]&&!ch[x][1])return fa[x]=ch[y][0]=0,upd(y),1;
	else return 0;
}
int A[500010],B[500010],FA[250010];
int HD(int x){return FA[x]==x?x:FA[x]=HD(FA[x]);}
void dfs(int x,int f=-1){
	for(int i=fir[x],u;i;i=nxt[i]){
		if(f==dis[i])continue;
		dfs(u=dis[i],x);
		makert(x);
		access(u),splay(u),yes[u]=YES[u]=1;
		splay(x);int y=ch[x][1];
		while(1){
			down(y,0);
			if(!YES[ch[y][1]])y=ch[y][1];
			else if(!yes[y])break;
			else y=ch[y][0];
		}
		int a=HD(A[y]),b=HD(B[y]);
		if(a!=u)std::swap(a,b),std::swap(A[y],B[y]),assert(a==u);
		splay(y),yes[y]=1;upd(y);
		printf("%d %d %d %d\n",x,u,A[y],B[y]);
		cut(B[y],y);link(B[y]=x,y);
		FA[HD(u)]=HD(x);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<n;++i)a=gi(),b=gi(),Link(a,b),Link(b,a);
	for(int i=0;i<=n;++i)yes[i]=YES[i]=1,FA[i]=i;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,i+n),link(b,i+n),A[i+n]=a,B[i+n]=b;
	printf("%d\n",n-1),dfs(1);
	return 0;
}