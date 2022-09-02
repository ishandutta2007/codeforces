//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;
const int MAXLOG = 18;

pair<ll, ll> a[MAXN];

int up[MAXLOG][MAXN];
int h[MAXN];


int getup(int a, int h){    
    for (int i = 0; i < MAXLOG; i++)
        if (h & (1<<i))
            a = up[i][a];
    return a;
}


int lca(int a, int b){
    if (h[a] < h[b]) swap(a,b);
//  eprintf("! %d %d\n", h[a], h[b]);
    a = getup(a, h[a] - h[b]);
//  eprintf("? %d %d\n", h[a], h[b]);
    assert(h[a] == h[b]);
    if (a == b) return a;
    for (int i = MAXLOG - 1; i >= 0; i--)
        if (up[i][a] != up[i][b])
            a = up[i][a], b = up[i][b];
    return up[0][a];
}

bool bad(const pair<ll, ll>& a, const pair<ll, ll>& b, const pair<ll, ll>& c){
    ll x1 = a.first - c.first;
    ll x2 = b.first - c.first;
    ll y1 = a.second - c.second;
    ll y2 = b.second - c.second;
    return x1 * y2 - x2 * y1 < 0;
}

vector<int> getp(int a){
    vector<int> res;
    while (a != up[0][a]){
        res.pb(a);
        a = up[0][a];
    }
    res.pb(a);
    return res;
}

int lca2(int a, int b){
    if (a == b) return a;
    vector<int> pa = getp(a);
    vector<int> pb = getp(b);
    int last = -1;
    while (pa.back() == pb.back()) last = pa.back(), pa.pop_back(), pb.pop_back();
    return last;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        scanf(LLD " " LLD, &a[i].first, &a[i].second);
    }

    vector<int> v;
    for (int i = 0; i < MAXLOG; i++)
        up[i][n-1] = n - 1;
    h[n-1] = 0;
    v.pb(n-1);

    for (int i = n - 2; i >= 0; i--){
        while (v.size() >= 2 && bad(a[v[v.size()-2]], a[v[v.size()-1]], a[i]))
            v.pop_back();
        assert(!v.empty());
        up[0][i] = v.back();
        h[i] = h[v.back()]+1;
//      eprintf("%d\n", up[0][i]);
        for (int j = 1; j < MAXLOG; j++) {
            up[j][i] = up[j-1][up[j-1][i]];
        }
        v.pb(i);
    }

/*  for (int i = 0; i < n; i++)
        for (int j = 0; j < MAXLOG; j++)
            assert(max(0,h[i] - (1<<j)) == h[up[j][i]]);*/

    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++){
        int a, b;
        scanf("%d %d",&a,&b);
        --a, --b;
        int c = lca(a, b);
        #ifdef LOCAL
            assert(c == lca2(a, b));
        #endif
        printf("%d ", c+1);
    }
    return 0;
}