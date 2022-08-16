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




#define oo              0xBADC0DE
#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define fill(a,v)       memset(a, v, sizeof a)
#define ull             unsigned long long
#define ll              long long
#define bitcount        __builtin_popcount
#define all(x)          x.begin(), x.end()
#define pb( z )         push_back( z )
#define gcd             __gcd
using namespace std;

const int mxn = (int)1e5 + 7;
pair<int,pair<int, int> > dom[mxn];
int x[mxn], h[mxn];
int n;

int dp[mxn];
int sol[mxn];
int tree[4*mxn];
int mp[mxn];
int offset;
void create(int node, int lo, int hi) {
    if (lo==hi) {
        mp[lo] = node;
        return;
    }
    int L = node<<1;
    int R = L+1;
    int mid = (lo+hi)>>1;
    create(L, lo, mid);
    create(R, mid+1, hi);
}
void increase() {
    offset++;
}
void update(int p, int val) {
    tree[mp[p]] = val-offset;
    int node = mp[p]>>1;
    while (node > 0) {
        int L = node<<1;
        int R = L+1;
        tree[node] = max(tree[L], tree[R]);
        node >>= 1;
    }
}

int query(int node, int lo, int hi, int qlo, int qhi) {
    if (lo > qhi || hi < qlo) {
        return -(int)1e9;
    }
    if (qlo <= lo && hi <= qhi) {
        return offset + tree[node];
    }
    int L = node<<1;
    int R = L+1;
    int mid = (lo+hi)>>1;
    return max(query(L, lo, mid, qlo, qhi), query(R, mid+1, hi, qlo, qhi));
}


int main(){
    s(n);
    for (int i=0; i < n; i++) {
        s(dom[i].first); s(dom[i].second.first);
        dom[i].second.second = i;
    }
    sort( dom, dom + n );
    
    for (int i=0; i < n; i++) {
        x[i] = dom[i].first;
        h[i] = dom[i].second.first;
        //cout << x[i] << " " << h[i] << endl;
    }
    
    
    create(1, 0, n);
    dp[n] = 0;
    for (int i=n-1; i >= 0; i--) {
        increase();
        int lim = x[i] + h[i] - 1;
        int j = lower_bound(x, x+n, lim) - x;
        
        while (j >= i && x[j] > lim) j--;
        
        int v = j > i ? query(1, 0, n, i+1, j) : 1;
        dp[i] = v;
        update(i, v);
        //cout << i << " to " << j << " with value " << v << endl;
        
    }
    for (int i=0; i < n; i++) {
        sol[ dom[i].second.second ] = dp[i];
    }
    for (int i=0; i < n; i++) {
        printf("%d", sol[i]);
        if (i+1 == n) puts("");
        else printf(" ");
    }
    
    
    return 0;
}