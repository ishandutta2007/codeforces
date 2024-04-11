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
#include <functional>

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
    vector<pii> lr;
    set<Line> lines;
    int n;
    const ftype neginf = 2e18; //CHANGE
    const Line def{ 0,neginf };
    int largestEval;
    inline bool cmp(const ftype& lhs, const ftype& rhs) {
        return lhs < rhs; //CHANGE
    }
    inline ftype better(const ftype& lhs, const ftype& rhs) {
        return min(lhs, rhs); //CHANGE
    }
    void addLine(Line ln) {
        int i = 1;
        ll l = 0, r = 2 * largestEval + 1;
        lines.insert(ln);
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
                if (lr[i].ff == -1) {
                    lr[i].ff = ++n;
                    lr.push_back({ -1,-1 });
                    seg.push_back(def);
                }
                i = lr[i].ff;
                r = mid;
            }
            else {
                if (lr[i].ss == -1) {
                    lr[i].ss = ++n;
                    lr.push_back({ -1,-1 });
                    seg.push_back(def);
                }
                i = lr[i].ss;
                l = mid;
            }
        }
    }
    ftype query(ftype x) {
        ftype bst = neginf;
        int i = 1;
        ftype l = 0, r = 2 * largestEval + 1;
        while (true) {
            bst = better(bst, eval(seg[i], x));
            if (r - l == 1)
                break;
            int mid = (l + r) / 2;
            if (x + largestEval < mid) {
                if (lr[i].ff == -1)
                    break;
                i = lr[i].ff;
                r = mid;
            }
            else {
                if (lr[i].ss == -1)
                    break;
                i = lr[i].ss;
                l = mid;
            }
        }
        return bst;
    }
    void build(ftype large) { //queries are [-large, large]
        n = 1;
        this->largestEval = large;
        seg.assign(2, def);
        lr.assign(2, { -1,-1 });
    }
};

const int sz = 5e5;
int n;
ll a[sz], b[sz];
vector<int> adj[sz];
ll dp[sz];


LiChao* dfs(int src, int prv) {
    vector<LiChao*> lcs;
    LiChao* lc;
    for (int x : adj[src]) {
        if (x != prv) {
            lcs.push_back(dfs(x, src));
        }
    }
    if (lcs.empty()) {
        dp[src] = 0; 
        lc = new LiChao();
        lc->build(1e5 + 5);
    }
    else {
        int m = lcs.size(), mx = lcs[0]->lines.size(), mxi = 0;
        foru(i, 1, m) {
            if (lcs[i]->lines.size() > mx) {
                mx = lcs[i]->lines.size(), mxi = i;
            }
        }
        lc = lcs[mxi];
        foru(i, 0, m) {
            if (i != mxi) {
                for (Line l : lcs[i]->lines) lc->addLine(l);
            }
        }
        dp[src] = lc->query(a[src]);
    }
    lc->addLine(Line{ b[src], dp[src] });
    return lc;
}

int main() {
    fast;
    cin >> n;
    foru(i, 0, n)cin >> a[i];
    foru(i, 0, n)cin >> b[i];
    foru(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
    foru(i, 0, n)cout << dp[i] << ' ';
	return 0;
}