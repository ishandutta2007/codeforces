#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1222222;
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
int n,x[maxn],y[maxn],tmpx[maxn],xl,tmpy[maxn],yl,deg[maxn],el=1,head[maxn],to[maxn],nxt[maxn];
char s[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	for(int &i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!s[i>>1]){
			s[i>>1]=v>xl?'r':'b';
			dfs(v);
		}
	}
}
int main(){
	n=read();
	FOR(i,1,n){
		tmpx[++xl]=x[i]=read();
		tmpy[++yl]=y[i]=read();
	}
	sort(tmpx+1,tmpx+xl+1);xl=unique(tmpx+1,tmpx+xl+1)-tmpx-1;
	sort(tmpy+1,tmpy+yl+1);yl=unique(tmpy+1,tmpy+yl+1)-tmpy-1;
	FOR(i,1,n){
		x[i]=lower_bound(tmpx+1,tmpx+xl+1,x[i])-tmpx;
		y[i]=lower_bound(tmpy+1,tmpy+yl+1,y[i])-tmpy;
		add(x[i],y[i]+xl);add(y[i]+xl,x[i]);
		deg[x[i]]++;deg[y[i]+xl]++;
	}
	FOR(i,1,xl+yl) if(deg[i]&1) add(i,xl+yl+1),add(xl+yl+1,i);
	FOR(i,1,xl+yl+1) dfs(i);
	FOR(i,1,n) printf("%c",s[i]);
}