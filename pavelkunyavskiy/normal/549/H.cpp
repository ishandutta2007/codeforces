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

#define TASKNAME "H"

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


struct segment{
    ld l, r;
    segment(){};
    segment(ld l, ld r):l(l),r(r){}
    segment(ld a, ld b, ld c, ld d){
        l = min(min(a, b), min(c, d));
        r = max(max(a, b), max(c, d));
    }
};

segment operator*(const segment& a, const segment& b){
    return segment(a.l * b.r, a.l * b.l, a.r * b.l, a.r * b.r);
}

segment operator-(const segment& a, const segment& b){
    return segment(a.l - b.r, a.r - b.l);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    int a, b, c, d;
    while (scanf("%d%d%d%d",&a,&b,&c,&d) == 4){
        ld l = 0;
        ld r = 1.1e9;
        for (int i = 0; i < 100; i++){
            ld m = (l + r)/2;
            segment A(a - m, a + m);
            segment B(b - m, b + m);
            segment C(c - m, c + m);
            segment D(d - m, d + m);
            segment res = A * D - B * C;
            if (res.l <= 0 && 0 <= res.r){
                r = m;
            } else {
                l = m;
            }
        }
        printf("%.10f\n", double(l+r)/2);
    }
      
  return 0;
}