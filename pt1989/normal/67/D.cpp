//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo          0xBADC0DE
#define getcx getchar
inline void s( int &n ) {
    n=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' ) ch=getcx();
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define fill(a,v)       memset(a, v, sizeof a)
#define ull             unsigned long long
#define ll              long long
#define bitcount        __builtin_popcount
#define all(x)          x.begin(), x.end()
#define pb( z )         push_back( z )
#define gcd             __gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;
int n;
const int mxn = 1<<20;
int x[mxn], y[mxn];
int yinv[mxn];
int a[mxn];

int tree[4*mxn];
int inv[mxn];
void create(int node, int lo, int hi) {
    if (lo==hi) {
        tree[node] = 0;
        inv[lo] = node;
        return;
    }
    int L = node<<1;
    int R = L + 1;
    int mid = (lo+hi)>>1;
    create(L, lo, mid);
    create(R, mid+1, hi);
}

int qmax(int node, int lo, int hi, const int qlo, const int qhi) {
    if (hi < qlo || lo > qhi || lo > hi) return 0;
    if (qlo <= lo && hi <= qhi) return tree[node];
    
    
    int L = node<<1;
    int R = L + 1;
    int mid = (lo+hi)>>1;
    return max( qmax(L, lo, mid, qlo, qhi), qmax(R, mid+1, hi, qlo, qhi) );
}
void update(int v, int val) {
    int node = inv[v];
    int old = tree[node];
    if (val <= old) return;
    tree[node] = val;
    node >>= 1;
    while (node > 0) {
        int L = node<<1;
        int R = L + 1;
        old = tree[node];
        tree[node] = max(tree[R], tree[L]);
        if (tree[node] == old) break;
        node >>= 1;
    }
    
}


int main(int argc, char** argv) {
    s(n);
    for (int i=1; i <= n; i++) {
        s(x[i]);
    }
    for (int i=1; i <= n; i++) {
        s(y[i]);
        yinv[ y[i] ] = i;
    }
    
    for (int i=1; i <= n; i++) {
        a[i] = n - yinv[ x[i] ] + 1;
    }
    
    create(1, 1, n);
    int sol = 1;
    for (int i=n; i >= 1; i--) {
        int q = a[i];
        int ans = 1 + qmax(1, 1, n, q+1, n);
        update( q, ans );
        sol = max(sol, ans);
    }
    printf("%d\n", sol);
    
    
    
    return 0;
}