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
#define TIMESTAMPf(x, ...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

#ifdef LOCAL

static struct __timestamper {
    string what;

    __timestamper(const char *what) : what(what) { };

    __timestamper(const string &what) : what(what) { };

    ~__timestamper() {
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");

#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

int A;

int get_minval(vector<pair<ll, int>>& cur, vector<ll>&  psum, int n, long long m) {
    int l = 0;
    int r = A + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int id = lower_bound(cur.begin(), cur.begin() + n, mid, [](const pair<ll, int> &a, int x) {
            return a.first < x;
        }) - cur.begin();
        if (mid * 1LL * id - psum[id] <= m)
            l = mid;
        else
            r = mid;
    }
    return l;
}


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n, cf, cm;
    long long m;
    scanf("%d %d %d %d %lld", &n, &A, &cf, &cm, &m);

    vector<pair<ll, int> > cur(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cur[i].first);
        cur[i].second = i;
    }

    sort(cur.begin(), cur.end());


    vector<ll> psum(n+1);
    for (int i = 0; i < n; i++){
        psum[i + 1] = psum[i] + cur[i].first;
    }

    int ans_val = get_minval(cur, psum, n, m);
    long long answer = ans_val * 1LL * cm;

    ll mbak = m;
    for (int i = n - 1; i >= 0; i--) {
        m -= A - cur[i].first;
        if (m < 0) break;
        int cur_val = get_minval(cur, psum, i, m);
        long long cur_ans = cur_val * 1LL * cm + (n - i) * 1LL * cf;
        if (cur_ans > answer) {
            answer = cur_ans;
            ans_val = cur_val;
        }
    }

    m = mbak;


    printf("%lld\n", answer);
    for (int i = 0; i < n; i++) {
        ll dlt = max(0LL, ans_val - cur[i].first);
        m -= dlt;
        cur[i].first += dlt;
    }
    for (int i = n - 1; i >= 0; i--) {
        ll dlt = min(m, A - cur[i].first);
        m -= dlt;
        cur[i].first += dlt;
    }
    sort(cur.begin(), cur.end(), [](const pair<int,int>& a, const pair<int, int>& b) { return a.second < b.second;});
    for (int i = 0; i < n; i++)
        printf("%lld%c", cur[i].first, " \n"[i == n-1]);
    return 0;
}