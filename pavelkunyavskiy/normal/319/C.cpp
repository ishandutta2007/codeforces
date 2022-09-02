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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;


namespace Convex{
    vector<ll> as;
    vector<ll> bs;
    vector<ll> xs;

    void init(ll a,ll b){
        as.pb(a);
        bs.pb(b);
        xs.pb(0);
    }

    ll get(ll x){
        assert(!xs.empty() && x >= *xs.begin());
        int id = upper_bound(xs.begin(),xs.end(),x) - xs.begin() - 1;
        return as[id] * x + bs[id];
    }

    void push(ll a,ll b){
        while (as.size() && as.back() * xs.back() + bs.back() >= a * xs.back() + b){
            as.pop_back();
            bs.pop_back();
            xs.pop_back();
        }
        assert(as.size());
        assert(a < as.back());
        ll xres = (b - bs.back() + (as.back() - a - 1)) / (as.back() - a);
/*      if (xres < xs.back()){
            eprintf(LLD"\n",as.back() * xs.back() + bs.back());
            eprintf(LLD"\n",a * xs.back() + b);
            eprintf(LLD" "LLD"\n",a,b);
            eprintf(LLD" "LLD"\n",as.back(),bs.back());
            eprintf(LLD"\n",xs.back());
            eprintf(LLD"\n",xres);
        }*/
        assert(xres >= xs.back());
        if (xres <= 10000000000LL){
            xs.pb(xres);
            as.pb(a);
            bs.pb(b);
        }
    }
}


int a[110000];
int b[110000];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    for (int i = 0; i < n; i++)
        scanf("%d",&b[i]);

    Convex::init(b[0],0);
    for (int i = 1; i < n-1; i++){
        assert(b[i] < b[i-1]);
        ll res = Convex::get(a[i]);
        Convex::push(b[i], res);
    }

    printf(LLD"\n",Convex::get(a[n-1]));

        
    TIMESTAMP(end);
    return 0;
}