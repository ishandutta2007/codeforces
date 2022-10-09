//byqingyu
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define LL long long

struct edge{
    int x, y, v; bool c;
    inline void input(){ scanf( "%d%d%d", &x, &y, &v ); c = 0; }
    bool operator < ( const edge &t )const{ return v < t.v; }
}a[MAXN];

int N, M;
int fa[MAXN];
int hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
int ft[MAXN][20], mx[MAXN][20], dep[MAXN];

void Add( int x, int y, int z ){
    nxt[++tot] = hd[x]; hd[x] = tot; to[tot] = y; val[tot] = z;
    nxt[++tot] = hd[y]; hd[y] = tot; to[tot] = x; val[tot] = z;
}

int find( int x ){ return fa[x] == x ? x : ( fa[x] = find(fa[x]) ); }
//LCA????????????
void DFS( int x ){
    dep[x] = dep[ft[x][0]] + 1;
    for ( int i = 1; i <= 17; ++i ) ft[x][i] = ft[ft[x][i - 1]][i - 1], mx[x][i] = max( mx[x][i - 1], mx[ft[x][i - 1]][i - 1] );
    for ( int i = hd[x]; i; i = nxt[i] ) if ( to[i] != ft[x][0] ) ft[to[i]][0] = x, mx[to[i]][0] = val[i], DFS(to[i]);
}

int LCA( int x, int y ){
    int ans(INT_MIN);
    if ( dep[x] < dep[y] ) swap( x, y );
    for ( int i = 17; i >= 0; --i ) if ( dep[ft[x][i]] > dep[y] ) ans = max( ans, mx[x][i] ), x = ft[x][i];
    if ( dep[x] > dep[y] ) ans = max( ans, mx[x][0] ), x = ft[x][0];
    for ( int i = 17; i >= 0; --i ) if ( ft[x][i] != ft[y][i] ) ans = max( ans, max( mx[x][i], mx[y][i] ) ), x = ft[x][i], y = ft[y][i];
    if ( x != y ) ans = max( ans, max( mx[x][0], mx[y][0] ) ), x = ft[x][0], y = ft[y][0];
    return ans;
}

int main(){
    scanf( "%d%d", &N, &M );
    for ( int i = 1; i <= M; ++i ) a[i].input(), fa[i] = i;//?????????????????
    sort( a + 1, a + M + 1 );//??
    int c(0);
    for ( int i = 1; i <= M; ++i ){
        int x(find(a[i].x)), y(find(a[i].y));
        if ( x != y ){
            fa[x] = y; c++; a[i].c = 1; Add( a[i].x, a[i].y, a[i].v );//????????a[i].c?????????????
            if ( c >= N - 1 ) break;//??????,??
        }
    }
    ft[1][0] = 1; mx[1][0] = INT_MIN; DFS(1);//?????ft???????mx
    LL ans(0);//???long long
    for ( int i = 1; i <= M; ++i ){
        if ( !a[i].c ){//??????????,????
            int t(LCA( a[i].x, a[i].y ));
            if ( a[i].v <= t ) ans += t + 1 - a[i].v;//????????,???
        }
    }
    printf( "%lld\n", ans );
    return 0;
}