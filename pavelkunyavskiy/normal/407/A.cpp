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

#define TASKNAME "A"

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


vector<pair<int,int> > genPt(int len){
    vector<pair<int,int> > res;
    for (int i = 0; i * i <= len * len; i++)
        for (int j = 0; i * i + j * j <= len * len; j++)
            if (i * i + j * j == len * len){
                res.pb(mp(+i, +j));
                res.pb(mp(-i, +j));
                res.pb(mp(+i, -j));
                res.pb(mp(-i, -j));
            }
    return res;
}

bool check(const pair<int,int>& a, const pair<int,int>& b){
    if (a.first * b.first + a.second * b.second) return false;
    if (!a.first || !b.first || !a.second || !b.second) return false;
    if (a.first == b.first || a.second == b.second) return false;
    return true;
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int a, b;
    while (scanf("%d %d",&a,&b) == 2){
        vector< pair<int,int> > v1 = genPt(a);
        vector< pair<int,int> > v2 = genPt(b);
        for (int i = 0; i < (int)v1.size(); i++)
            for (int j = 0; j < (int)v2.size(); j++){
                if (check(v1[i], v2[j])){
                    printf("YES\n0 0\n%d %d\n%d %d\n", v1[i].first, v1[i].second, v2[j].first, v2[j].second);
                    goto end;
                }
            }
        printf("NO\n");
        end:;
    }
    return 0;
}