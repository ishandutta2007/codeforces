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

#define TASKNAME "F"

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

long long ans;
int mod;

int norm(int x){
    return (x % mod + mod) % mod;
}

struct Map {
    map<int, int> val;
    int shift;
    int total;
    int get(int x){
        x = norm(x - shift);
        if (val.count(x)) return val[x];
        return 0;
    }
    void put(int x, int cnt){
        x = norm(x - shift);
        val[x] += cnt;
    }
    void addTotal(int x){
        total = (total + x) % mod;
    }
    void swap(Map& r){
        ::swap(r.shift, shift);
        ::swap(r.total, total);
        r.val.swap(val);
    }
    void add(int x){
        shift = norm(shift + x);
    }
    int conv(int key){
        return norm(key + shift);
    }
};



vector<int> p;
vector<Map> v;

int get(int a){
    if (a == p[a]) return a;
    return p[a] = get(p[a]);
}



int main(){
#ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
#endif
    int n;
    scanf("%d%d",&n, &mod);
    p.resize(n);
    v.resize(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    for (int i = 0; i < n; i++){
        p[i] = i;
    }
    sort(a.begin(), a.end());
    vector<bool> used(n);
    for (int i = 0; i < n; i++){
        //eprintf("%lld\n", ans);
        int pos = a[i].second;
        bool haveLeft = pos && used[pos-1];
        bool haveRight = pos != n-1 && used[pos+1];
        used[pos] = true;
        if (haveLeft && haveRight) {
            Map& mLf = v[get(pos-1)];
            Map& mRg = v[get(pos+1)];
            int need = mLf.total;
            int inv1 = -1, inv2 = -1;
            bool swapped = false;
            if (mLf.val.size() > mRg.val.size()) {
                mLf.swap(mRg), swapped = true;
                inv1 = 1, inv2 = 1;
            }
            for (auto x : mLf.val){
                int should = norm((need + mLf.conv(x.first) * inv1) * inv2);
                ans += x.second * 1LL * mRg.get(should);
            }
            if (swapped){
                mLf.swap(mRg);
            }
            mRg.add(mLf.total + a[i].first);
            if (mLf.val.size() > mRg.val.size())
                mLf.swap(mRg);
            for (auto x : mLf.val){
                mRg.put(mLf.conv(x.first), x.second);
            }
            mRg.addTotal(mLf.total + a[i].first);
            mRg.swap(v[pos]);
            p[get(pos-1)] = p[get(pos+1)] = pos;
        } else if (haveLeft) {
            p[pos] = pos - 1;
            Map& m = v[get(pos)];
            ans += m.get(m.total);
            m.put(a[i].first + m.total, 1);
            m.addTotal(a[i].first);
        } else if (haveRight) {
            p[pos] = pos + 1;
            Map& m = v[get(pos)];
            ans += m.get(0);
            m.add(a[i].first);
            m.put(0, 1);
            m.addTotal(a[i].first);
        } else {
            v[pos].put(0, 1);
            v[pos].put(a[i].first, 1);
            v[pos].addTotal(a[i].first);
            ans++;
        }
    }
    printf("%lld\n", ans - n);
    return 0;
}