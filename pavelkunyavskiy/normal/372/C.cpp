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

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#endif

typedef long long ll;
typedef long double ld;

const ll inf = 1LL<<60;

struct MaxStack {
    vector<ll> val;
    vector<ll> best;

    MaxStack(){
        best.pb(-inf);
    }

    void push(ll x){
        val.pb(x);
        best.pb(max(x, best.back()));
    }

    ll getMax(){
        return best.back();
    }

    ll pop(){
        ll temp = val.back();
        val.pop_back();
        best.pop_back();
        return temp;
    }
    bool empty(){
        return val.empty();
    }
};

struct MaxQueue {
    MaxStack s1,s2;

    void push(ll x){
        s1.push(x);
    }
    ll pop(){
        if (s2.empty()){
            while (!s1.empty())
                s2.push(s1.pop());
        }
        assert(!s2.empty());
        return s2.pop();
    }
    ll getMax(){
        return max(s1.getMax(), s2.getMax());
    }
};

const int MAXN = 151000;

ll ans[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,m,d;
    scanf("%d %d %d",&n,&m,&d);

    memset(ans, 0, sizeof(ans));

    int last = 0;

    for (int it = 0; it < m; it++){
        int a, b, t;
        scanf("%d %d %d",&a,&b,&t);
        --a;
        int shift = min(n*1LL, d * 1LL * (t - last));
        MaxQueue q;
        int ptr1 = 0, ptr2 = 0;
        for (int j = 0; j < n; j++){
            while (ptr1 < n && (ptr1 - j <= shift))
                q.push(ans[ptr1++]);
            while (ptr2 < n && (j - ptr2 > shift))
                q.pop(), ptr2++;
            ans[j] = q.getMax() + b - abs(a - j);
        }
        last = t;
    }

    printf(LLD"\n", *max_element(ans, ans + n));      
    return 0;
}