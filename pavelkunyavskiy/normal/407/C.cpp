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
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 1.1e5;

const int MOD = 1000000007;

void madd(int& a, int b){
    if ((a += b) >= MOD) a -= MOD;
}

int mmul(int a, int b){
    return ll(a) * b % MOD;
}

int mpow(int a, int b){
    int res = 1;
    for (;b; b >>= 1){
        if (b & 1) res = mmul(res, a);
        a = mmul(a, a);
    }
    return res;
}

int f[MAXN];
int invf[MAXN];

int cnk(int n, int k){
    if (n < k) return 0;
    return mmul(f[n], mmul(invf[k], invf[n-k]));
}

int cnkrep(int n, int k){
    return cnk(n + k - 1, k);
}



int a[MAXN];

const int MAXK = 100;

int coef[MAXK+1];
vector< pair<int,int> > evs[MAXK+1];
int ptr[MAXK + 1];



int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n,m;
    f[0] = invf[0] = 1;
    for (int i = 1; i < MAXN; i++){
        f[i] = mmul(f[i-1], i);
        invf[i] = mpow(f[i], MOD - 2);
    }

    while (scanf("%d%d", &n,&m) == 2){
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        for (int i = 0; i <= MAXK; i++)
            evs[i].clear(), coef[i] = 0, ptr[i] = 0;    

        for (int i = 0; i < m; i++){
            int l, r, k;
            scanf("%d %d %d",&l,&r,&k);
            --l, --r;
            evs[k].pb(mp(l, -1));
            evs[k].pb(mp(r, r - l + 1));
        }
        for (int i = 0; i <= MAXK; i++)
            sort(evs[i].begin(), evs[i].end());

        for (int i = 0; i < n; i++){
            for (int k = MAXK; k >= 0; k--){
                for (;ptr[k] < (int)evs[k].size() && evs[k][ptr[k]] == mp(i, -1); ptr[k]++){
//                      eprintf("+ %d 1\n", k);
                    madd(coef[k],1);
                }

            }                  
            for (int k = MAXK; k > 0; k--)
                madd(coef[k-1], coef[k]);
            madd(a[i], coef[0]);

            for (int k = MAXK; k >= 0; k--){
                for(;ptr[k] < (int)evs[k].size() && evs[k][ptr[k]].first == i; ptr[k]++){
                    for (int k2 = 0; k2 <= k; k2++) {
  //                        eprintf("- %d ?\n", k);
                        madd(coef[k2], MOD - cnkrep(evs[k][ptr[k]].second, k - k2));
                    }
                }
            }                  
        }

        for (int i = 0; i < n; i++)
            printf("%d%c", a[i]," \n"[i==n-1]);
    }


      
    return 0;
}