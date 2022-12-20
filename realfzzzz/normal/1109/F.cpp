#include<bits/stdc++.h>
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
const int maxn=2e5+5;
int n,m,p[maxn];
vector<int> f[maxn];
int fa[maxn],ch[maxn][2];
bool isroot(int x){
	int y=fa[x];
	return !y||(ch[y][0]!=x&&ch[y][1]!=x);
}
void rotate(int x){
	int y=fa[x],z=fa[y];
	if(!isroot(y)) ch[z][ch[z][1]==y]=x;
	bool d=ch[y][1]==x;
	int k=ch[x][!d];
	ch[y][d]=k;
	ch[x][!d]=y;
	if(k) fa[k]=y;
	fa[x]=z;
	fa[y]=x;
}
bool rev[maxn];
void pushtag(int x){
	rev[x]^=1;
	swap(ch[x][0],ch[x][1]);
}
void pushdown(int x){
	if(rev[x]){
		if(ch[x][0]) pushtag(ch[x][0]);
		if(ch[x][1]) pushtag(ch[x][1]);
		rev[x]=0;
	}
}
void pushall(int x){
	if(!isroot(x)) pushall(fa[x]);
	pushdown(x);
}
void splay(int x){
	pushall(x);
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			if((ch[y][1]==x)^(ch[z][1]==y)) rotate(x);
			rotate(y);
		}
		rotate(x);
	}
}
void access(int x){
	int y=0;
	while(x){
		splay(x);
		ch[x][1]=y;
		y=x;
		x=fa[x];
	}
}
int findroot(int x){
	access(x);
	splay(x);
	while(ch[x][0]){
		pushdown(x);
		x=ch[x][0];
	}
	splay(x);
	return x;
}
void makeroot(int x){
	access(x);
	splay(x);
	pushtag(x);
}
void link(int x,int y){
	makeroot(x);
	fa[x]=y;
}
void cut(int x,int y){
	makeroot(x);
	access(y);
	splay(x);
	ch[x][1]=fa[y]=0;
}
struct item{
	int mn,cnt;
	item operator +(item b){
		if(mn<b.mn) return {mn,cnt};
		else if(mn>b.mn) return {b.mn,b.cnt};
		else return{mn,cnt+b.cnt};
	}
};
struct node{
	int l,r;
	node* ch[2];
	item v;
	int add=0;
	void pushup(){
		v=ch[0]->v+ch[1]->v;
	}
	node(int l,int r):l(l),r(r),v({0,r-l+1}){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(int k){
		v.mn+=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,int k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
	item query(int ql,int qr){
		if(ql<=l&&qr>=r) return v;
		pushdown();
		item ans={(int)2e9,0};
		if(ql<=ch[0]->r) ans=ans+ch[0]->query(ql,qr);
		if(qr>=ch[1]->l) ans=ans+ch[1]->query(ql,qr);
		return ans;
	}
}*rt;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool check(int l,int r){
	int x=(p[r]-1)/m+1,y=(p[r]-1)%m+1;
	set<int> s;
	for(int i=0;i<4;i++){
		int vx=x+dx[i],vy=y+dy[i];
		if(vx<=0||vx>n||vy<=0||vy>m||f[vx][vy]<l||f[vx][vy]>=r) continue;
		int u=findroot(f[vx][vy]);
		if(s.find(u)!=s.end()) return 0;
		s.insert(u);
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++){
		f[i].resize(m+1);
		for(int j=1;j<=m;j++) p[f[i][j]=readint()]=(i-1)*m+j;
	}
	int cur=1;
	rt=new node(1,n*m);
	long long ans=0;
	for(int i=1;i<=n*m;i++){
		while(!check(cur,i)){
			int x=(p[cur]-1)/m+1,y=(p[cur]-1)%m+1;
			for(int j=0;j<4;j++){
				int vx=x+dx[j],vy=y+dy[j];
				if(vx<=0||vx>n||vy<=0||vy>m||f[vx][vy]<cur||f[vx][vy]>=i) continue;
				cut(cur,f[vx][vy]);
			}
			cur++;
		}
		rt->modify(1,i,1);
		int x=(p[i]-1)/m+1,y=(p[i]-1)%m+1;
		for(int j=0;j<4;j++){
			int vx=x+dx[j],vy=y+dy[j];
			if(vx<=0||vx>n||vy<=0||vy>m||f[vx][vy]<cur||f[vx][vy]>=i) continue;
			link(i,f[vx][vy]);
			rt->modify(1,f[vx][vy],-1);
		}
		ans+=rt->query(cur,i).cnt;
	}
	printf("%lld\n",ans);
	return 0;
}