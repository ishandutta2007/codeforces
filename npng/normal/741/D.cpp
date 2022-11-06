#include<bits/stdc++.h>
using namespace std;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 2000000 + 5 ; 
int n, cnt, idnex, L[N], R[N], head[N], dep[N], sz[N], son[N] ;
int book[N * 10], vis[N], Ans[N], dis[N], Id[N] ; 
struct E {
	int to, next, w ; 
} e[N] ;
void add( int x, int y, int w ) {
	e[++ cnt] = (E){ y, head[x], w }, head[x] = cnt ; 
}
void dfs( int x, int fa ) {
	sz[x] = 1, L[x] = ++ idnex, dep[x] = dep[fa] + 1, Id[idnex] = x ; 
	Next( i, x ) {
		int v = e[i].to ; dis[v] = dis[x] ^ e[i].w, dfs( v, x ), sz[x] += sz[v] ;
		if( sz[son[x]] < sz[v] ) son[x] = v ; 
	} R[x] = idnex ; 
}
void dfs2( int x, int keep ) {
	Next( i, x ) {
		int v = e[i].to ; if( v == son[x] ) continue ; 
		dfs2( v, 0 ), Ans[x] = max( Ans[x], Ans[v] ) ; 
	}
	if( son[x] ) dfs2( son[x], 1 ), Ans[x] = max( Ans[x], Ans[son[x]] ) ; 
	if( book[dis[x]] ) Ans[x] = max( Ans[x], book[dis[x]] - dep[x] ) ; 
	rep( i, 0, 21 ) if( book[dis[x] ^ ( 1 << i )] ) Ans[x] = max( Ans[x], book[dis[x] ^ ( 1 << i )] - dep[x] ) ; 
	book[dis[x]] = max( dep[x] , book[dis[x]] ) ;
	Next( i, x ) {
		int v = e[i].to ; if( v == son[x] ) continue ; 
		rep( j, L[v], R[v] ) {
			int u = Id[j] ; 
			if( book[dis[u]] ) Ans[x] = max( Ans[x], book[dis[u]] + dep[u] - 2 * dep[x] ) ; 
			rep( k, 0, 21 ) if( book[dis[u] ^ ( 1 << k )] ) Ans[x] = max( Ans[x], book[dis[u] ^ ( 1 << k )] + dep[u] - 2 * dep[x] ) ; 
		}
		rep( j, L[v], R[v] ) book[dis[Id[j]]] = max( book[dis[Id[j]]], dep[Id[j]] ) ; 
	}
	if( !keep ) rep( i, L[x], R[x] ) book[dis[Id[i]]] = 0 ; 
}
signed main(){
	n=read();
	int x;
	char ch ; 
	rep( i, 2, n ) {
		scanf("%d", &x), cin >> ch, add( x, i, 1ll << ( ch - 'a' ) ) ; 
	}
	dfs( 1, 1 ), dfs2( 1, 1 ) ;
	rep( i, 1, n ) printf("%d ", Ans[i] ) ;
	return 0;
}