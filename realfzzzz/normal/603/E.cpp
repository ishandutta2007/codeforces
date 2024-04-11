#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5,maxm=3e5+5;
int n,m,a[maxm],b[maxm],l[maxm];
int fa[maxn+maxm],ch[maxn+maxm][2];
bool isrt(int x){
	int y=fa[x];
	return !y||(ch[y][0]!=x&&ch[y][1]!=x);
}
int mx[maxn+maxm],s[maxn+maxm],s2[maxn+maxm];
void pushup(int x){
	mx[x]=x<=n?0:x-n;
	s[x]=s2[x]+(x<=n);
	for(int y:ch[x]) if(y){
		if(mx[y]&&(!mx[x]||l[mx[y]]>l[mx[x]])) mx[x]=mx[y];
		s[x]+=s[y];
	}
}
bool rev[maxn+maxm];
void pushtag(int x){
	swap(ch[x][0],ch[x][1]);
	rev[x]^=1;
}
void pushdown(int x){
	if(rev[x]){
		if(ch[x][0]) pushtag(ch[x][0]);
		if(ch[x][1]) pushtag(ch[x][1]);
		rev[x]=0;
	}
}
void rotate(int x){
	int y=fa[x],z=fa[y];
	if(!isrt(y)) ch[z][ch[z][1]==y]=x;
	bool d=ch[y][1]==x;
	int k=ch[x][!d];
	ch[x][!d]=y;
	ch[y][d]=k;
	fa[y]=x;
	fa[x]=z;
	if(k) fa[k]=y;
	pushup(y);
	pushup(x);
}
void pushall(int x){
	if(!isrt(x)) pushall(fa[x]);
	pushdown(x);
}
void splay(int x){
	pushall(x);
	while(!isrt(x)){
		int y=fa[x],z=fa[y];
		if(!isrt(y))
			rotate((ch[y][1]==x)^(ch[z][1]==y)?x:y);
		rotate(x);
	}
}
void access(int x){
	int y=0;
	while(x){
		splay(x);
		if(ch[x][1]) s2[x]+=s[ch[x][1]];
		ch[x][1]=y;
		if(y) s2[x]-=s[y];
		pushup(x);
		y=x;
		x=fa[x];
	}
}
void makert(int x){
	access(x);
	splay(x);
	pushtag(x);
}
int findrt(int x){
	access(x);
	splay(x);
	while(ch[x][0]){
		pushdown(x);
		x=ch[x][0];
	}
	splay(x);
	return x;
}
void link(int x,int y){
	makert(y);
	access(x);
	splay(x);
	fa[y]=x;
	s2[x]+=s[y];
	pushup(x);
}
void cut(int x,int y){
	makert(x);
	access(y);
	splay(x);
	ch[x][1]=fa[y]=0;
	pushup(x);
}
struct cmp{
	bool operator ()(int a,int b){
		if(l[a]!=l[b]) return l[a]>l[b];
		return a<b;
	}
};
set<int,cmp> st;
int cnt;
void add(int x){
	int u=findrt(a[x]),v=findrt(b[x]);
	if(u!=v){
		if(s[u]%2==1&&s[v]%2==1) cnt-=2;
		link(a[x],n+x);
		link(b[x],n+x);
		st.insert(x);
	}
	else{
		makert(a[x]);
		access(b[x]);
		splay(a[x]);
		int y=mx[a[x]];
		if(l[x]<l[y]){
			cut(a[y],n+y);
			cut(b[y],n+y);
			st.erase(y);
			link(a[x],n+x);
			link(b[x],n+x);
			st.insert(x);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=read();
	m=read();
	for(int i=1;i<=n+m;i++) pushup(i);
	cnt=n;
	for(int i=1;i<=m;i++){
		a[i]=read();
		b[i]=read();
		l[i]=read();
		add(i);
		if(cnt){
			printf("-1\n");
			continue;
		}
		while(1){
			int x=*st.begin();
			cut(a[x],n+x);
			cut(b[x],n+x);
			if(s[findrt(a[x])]%2==1){
				link(a[x],n+x);
				link(b[x],n+x);
				printf("%d\n",l[x]);
				break;
			}
			st.erase(x);
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}