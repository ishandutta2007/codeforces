#include<bits/stdc++.h>
using namespace std;
const int maxn=500050,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,sz[maxn],fa[maxn];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==y) return;
	fa[x]=y;sz[y]+=sz[x];
}
int main(){
	n=read();m=read();
	FOR(i,1,n) fa[i]=i,sz[i]=1;
	FOR(i,1,m){
		int x=read(),pre=0;
		while(x--){
			int y=read();
			if(pre) unite(y,pre);
			pre=y;
		}
	}
	FOR(i,1,n) printf("%d ",sz[getfa(i)]);
}