#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,cnt,ls[maxn],rs[maxn],fa[maxn];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void dfs(int x){
	if(ls[x]) dfs(ls[x]);
	if(x<=n) printf("%d ",x);
	if(rs[x]) dfs(rs[x]);
}
int main(){
	n=cnt=read();
	FOR(i,1,2*n) fa[i]=i;
	FOR(i,1,n-1){
		int x=read(),y=read();
		int u=getfa(x),v=getfa(y);
		ls[++cnt]=u;rs[cnt]=v;
		fa[u]=fa[v]=cnt;
	}
	dfs(cnt);
}