#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q,ans;
int ch[2000005][2],fa[2000005],mina[2000005],rev[2000005],val[2000005];
char a[100005][15];

bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
bool son(int x){return ch[fa[x]][1]==x;}
void reverse(int x){rev[x]^=1,swap(ch[x][0],ch[x][1]);}
void pushdown(int x){if(rev[x]) reverse(ch[x][0]),reverse(ch[x][1]),rev[x]=0;}
void update(int x){mina[x]=min(val[x],min(ch[x][0]?mina[ch[x][0]]:1<<30,ch[x][1]?mina[ch[x][1]]:1<<30));}

void rotate(int x){
	int y=fa[x],z=fa[y],k=son(x),w=ch[x][!k];
	if(nroot(y)) ch[z][son(y)]=x;
	ch[x][!k]=y,ch[y][k]=w;
	if(w) fa[w]=y;
	fa[y]=x,fa[x]=z;
	update(y),update(x);
}

void pushall(int x){
	if(nroot(x)) pushall(fa[x]);
	pushdown(x);
}

void splay(int x){
	pushall(x);
	while(nroot(x)){
		int y=fa[x];
		if(nroot(y)) rotate(son(x)==son(y)?y:x);
		rotate(x);
	}
}

void access(int x){for(int y=0;x;x=fa[y=x]) splay(x),ch[x][1]=y,update(x);}
void makeroot(int x){access(x); splay(x); reverse(x);}
void link(int x,int y){makeroot(x); makeroot(y); if(nroot(x)||nroot(y)) return; fa[x]=y;}
void cut(int x,int y){makeroot(x); access(y); splay(x); if(ch[x][son(y)]!=y) return; ch[x][son(y)]=0,fa[y]=0; update(x);}
int id(int x,int y){return (x-1)*(m+2)+y;}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n+2;i++) for(int j=1;j<=m+2;j++) mina[id(i,j)]=val[id(i,j)]=1<<30;
	for(int i=2;i<=m+2;i++) link(id(1,i),id(1,1)),mina[id(1,i)]=val[id(1,i)]=id(1,i);
	for(int i=2;i<=n+1;i++) link(id(i,1),id(1,1)),link(id(i,m+2),id(1,1)),mina[id(i,1)]=val[id(i,1)]=id(i,1),mina[id(i,m+2)]=val[id(i,m+2)]=id(i,m+2);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='^') link(id(i+1,j+1),id(i,j+1));
			else if(a[i][j]=='<'&&(j==1||a[i][j-1]!='>')) link(id(i+1,j+1),id(i+1,j));
			else if(a[i][j]=='>'&&(j==m||a[i][j+1]!='<')) link(id(i+1,j+1),id(i+1,j+2));
		}
	}
	char opt,z; int x,y;
	while(q--){
		cin>>opt; x=readint(); y=readint();
		if(opt=='C'){
		    cin>>z;
			if(a[x][y]=='^') cut(id(x+1,y+1),id(x,y+1));
			else if(a[x][y]=='<'&&(y==1||a[x][y-1]!='>')) cut(id(x+1,y+1),id(x+1,y));
			else if(a[x][y]=='>'&&(y==m||a[x][y+1]!='<')) cut(id(x+1,y+1),id(x+1,y+2));
			if(a[x][y]=='<'&&z!='<'&&y>1&&a[x][y-1]=='>') link(id(x+1,y),id(x+1,y+1));
			else if(a[x][y]=='>'&&z!='>'&&y<m&&a[x][y+1]=='<') link(id(x+1,y+2),id(x+1,y+1));
			if(a[x][y]!='<'&&z=='<'&&y>1&&a[x][y-1]=='>') cut(id(x+1,y),id(x+1,y+1));
			else if(a[x][y]!='>'&&z=='>'&&y<m&&a[x][y+1]=='<') cut(id(x+1,y+2),id(x+1,y+1));
			if(z=='^') link(id(x+1,y+1),id(x,y+1));
			else if(z=='<'&&(y==1||a[x][y-1]!='>')) link(id(x+1,y+1),id(x+1,y));
			else if(z=='>'&&(y==m||a[x][y+1]!='<')) link(id(x+1,y+1),id(x+1,y+2));
			a[x][y]=z;
		}
		else{
			makeroot(id(1,1)); makeroot(id(x+1,y+1));
			if(!nroot(id(1,1))) printf("-1 -1\n");
			else{
				ans=mina[id(x+1,y+1)];
				printf("%d %d\n",(ans-1)/(m+2),(ans-1)%(m+2));
			}
		}
	}
	return 0;
}