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

#define TASKNAME "E"

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


int res[(1<<24) + 10];
int res0[(1<<24) + 10];

vector<int> msk;

void readOne(){
    char buf[5];
    scanf("%s", buf);
    sort(buf, buf+3);
    int id = unique(buf, buf + 3) - buf;
    if (id == 1) {
        res[1<<(buf[0] - 'a')]++;
        msk.pb(1<<(buf[0] - 'a'));
    }   
    if (id == 2){
        int m1 = 1<<(buf[0] - 'a');
        int m2 = 1<<(buf[1] - 'a');
        msk.pb(m1 | m2);
        res[m1   ]++;
        res[   m2]++;
        res[m1|m2]--;
    }
    if (id == 3){
        int m1 = 1<<(buf[0] - 'a');
        int m2 = 1<<(buf[1] - 'a');
        int m3 = 1<<(buf[2] - 'a');
        msk.pb(m1 | m2 | m3);
        res[m1      ]++;
        res[   m2   ]++;
        res[      m3]++;
        res[   m2|m3]--;
        res[m1|   m3]--;
        res[m1|m2   ]--;
        res[m1|m2|m3]++;
    }
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        readOne();

//  for (int i = 0; i <= 7; i++)
//      eprintf("%d%c", res[i], " \n"[i==7]);

    int ans = 0;
    for (int i = 1; i < (1<<24); i++){
        int m1 = i & ~(i - 1);
        if (m1 == i) {
//              eprintf("%d %d\n", i, res[i]);
            ans ^= (res[i] * res[i]);
            continue;
        }
        res0[i] = res[i];
        int m2 = (i ^ m1) & ~((i ^ m1) - 1);
        if (i == (m1 ^ m2))
            res[i] += res[i ^ m1] + res[i ^ m2] - res[i ^ m1 ^ m2];
        else {
            int m3 = (i ^ m1 ^ m2) & ~((i ^ m1 ^ m2) - 1);
            res[i] = res[i ^ m1] + res[i ^ m2] + res[i ^ m3] - res[i ^ m1 ^ m2] - res[i ^ m1 ^ m3] - res[i ^ m2 ^ m3] + res[i ^ m1 ^ m2 ^ m3];
            res[i] += res0[m1 ^ m2 ^ m3];
        }

        ans ^= (res[i] * res[i]);
/*          #ifdef LOCAL
        int cnt = 0;
        for (int j = 0; j < (int) msk.size(); j++)
            if (i & msk[j])
                cnt++;
//          eprintf("%d %d %d\n", i, cnt, res[i]);
        assert(cnt == res[i]);
        #endif*/
    }

    printf("%d\n", ans);
      
  return 0;
}