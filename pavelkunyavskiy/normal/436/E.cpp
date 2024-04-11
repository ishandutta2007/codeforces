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


struct Magic {
    multiset<int> a, b;
    ll sum;
    int cnt;

    Magic(){
        sum = cnt = 0;
    }

    void insert(int val) {
        b.insert(val);
        norm();
    }
    void erase(int val) {
        if (b.find(val) != b.end()) {
            b.erase(b.find(val));
            return;
        }
        assert(a.find(val) != a.end());
        a.erase(a.find(val));
        sum -= val;
        norm();
    }
    void decCnt(){
        cnt--;
        norm();
    }
    void norm(){
        while ((int)a.size() > cnt && !a.empty()) {
            b.insert(*--a.end());
            sum -= *--a.end();
            a.erase(--a.end());
        }
        while ((int)a.size() < cnt && !b.empty()) {
            sum += *b.begin();
            a.insert(*b.begin());
            b.erase(b.begin());
        }
        while (!a.empty() && !b.empty()){
            int val1 = *--a.end();
            int val2 = *b.begin();
            if (val1 <= val2) break;
            a.erase(--a.end());
            b.erase(b.begin());
            a.insert(val2);
            b.insert(val1);
            sum += val2 - val1;
        }
    }
    ll get(){
        if ((int)a.size() < cnt) return 1LL<<60;
        return sum;
    }
};

struct Level {
    int id;
    int a, b;
    bool operator<(const Level& r) const{
        return b < r.b;
    }
};

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n,w;
    scanf("%d%d",&n,&w);
    vector<Level> v(n);
    for (int i = 0; i < n; i++){
        v[i].id = i;
        scanf("%d%d",&v[i].a,&v[i].b);
    }
    sort(v.begin(), v.end());
    Magic s;
    s.cnt = w;
    for (int i = 0; i < n; i++)
        s.insert(v[i].a);

    ll ans = 1LL<<60;
    int ansp = -1;
    ll cur = 0;

    for (int i = 0; i <= n; i++){
        if (s.get()+cur < ans){
            ans = s.get()+cur;
            ansp = i;
        }
        if (i == n) continue;
        s.decCnt();
        if (s.cnt < 0) break;
        s.erase(v[i].a);
        cur += v[i].a;
        s.insert(v[i].b - v[i].a);
    }

    printf(LLD"\n", ans);
    vector<int> res(n);
    vector<pair<int, int> > b;
    for (int i = 0; i < n; i++)
        if (i < ansp) {
            res[v[i].id]++;
            b.pb(mp(v[i].b - v[i].a, v[i].id));
        } else {
            b.pb(mp(v[i].a, v[i].id));
        }

    sort(b.begin(), b.end());
    for (int i = 0; i < w - ansp; i++) 
        res[b[i].second]++;

    for (int i = 0; i < n; i++)
        printf("%d", res[i]);
    printf("\n");

    return 0;
}