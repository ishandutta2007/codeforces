#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <complex>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

typedef ll ftype;
typedef pair<ftype, ftype> Line;

ftype eval(const Line & ln, const ftype & x) {
    return ln.ff * x + ln.ss;
}

struct LiChao { //maximum
    vector<Line> seg;
    int n;
    const ftype neginf = -1e16; //CHANGE
    int largestEval;
    inline bool cmp(const ftype& lhs, const ftype& rhs) {
        return lhs > rhs; //CHANGE
    }
    inline ftype better(const ftype& lhs, const ftype& rhs) {
        return max(lhs, rhs); //CHANGE
    }
    void addLine(Line ln) {
        int i = 1, l = 0, r = 2 * largestEval + 1;
        while (true) {
            if (ln == seg[i])return;
            int mid = (l + r) / 2;
            int realL = l - largestEval, realMid = mid - largestEval;
            bool lBetter = cmp(eval(ln, realL), eval(seg[i], realL));
            bool midBetter = cmp(eval(ln, realMid), eval(seg[i], realMid));
            if (midBetter)
                swap(seg[i], ln);
            if (r - l == 1)
                return;
            else if (midBetter != lBetter) {
                i <<= 1;
                r = mid;
            }
            else {
                i <<= 1; i++;
                l = mid;
            }
        }
    }
    ftype query(ftype x) {
        ftype bst = neginf;
        int i = 1, l = 0, r = 2 * largestEval + 1;
        while (true) {
            bst = better(bst, eval(seg[i], x));
            if (r - l == 1)
                break;
            int mid = (l + r) / 2;
            if (x + largestEval < mid) {
                i <<= 1;
                r = mid;
            }
            else {
                i <<= 1; i++;
                l = mid;
            }
        }
        return bst;
    }
    void build(int large) { //queries are [-large, large]
        this->largestEval = large;
        Line def(0, neginf);
        seg.assign(8 * this->largestEval + 5, def);
    }
};

const int sz = 3e5;
int n;
ll a[sz], p[sz], van, bst;

int main() {
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        van += a[i] * i;
        p[i] = a[i] + p[i - 1];
    }
    bst = van;
    LiChao lc;
    lc.build(1e6 + 5);
    for (int i = 1; i <= n; i++) {
        bst = max(bst, van + p[i - 1] - a[i] * i + lc.query(a[i]));
        Line nl(i, -p[i - 1]);
        lc.addLine(nl);
    }
    lc.build(1e6 + 5);
    for (int i = n; i >= 1; i--) {
        bst = max(bst, van + p[i] - a[i] * i + lc.query(a[i]));
        Line nl(i, -p[i]);
        lc.addLine(nl);
    }
    cout << bst;
    return 0;
}