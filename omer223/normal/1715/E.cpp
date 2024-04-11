#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>
#include <numeric>
#include <complex>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;

/*
Author: Omer223
Purpose: Li Chao tree, not sparse, supports negatives. Defaulted to maximum.
Date: 17/9/2021
Confirmed: Yes, https://codeforces.com/contest/631/problem/E
*/
typedef ll ftype;
typedef complex<ftype> pt;

ftype dot(const pt & a, const pt & b) {
    return (conj(a) * b).real();
}

struct Line {
    pt l;
    Line(ftype m, ftype b) {
        l = { m,b };
    }
    ftype eval(ftype x) {
        return dot(l, { x, 1 });
    }
    const bool operator==(Line other) {
        return l == other.l;
    }
};

struct LiChao { //min
private:
    vector<Line> seg;
    int n;
    const ftype neginf = 1e16; //CHANGE
    inline bool cmp(const ftype& lhs, const ftype& rhs) {
        return lhs < rhs; //CHANGE
    }
    inline ftype better(const ftype& lhs, const ftype& rhs) {
        return min(lhs, rhs); //CHANGE
    }
    void addLine(Line ln, int i, int l, int r) { //r excluded
        if (ln == seg[i])return;
        int mid = (l + r) / 2;
        int realL = l - n, realMid = mid - n;
        bool lBetter = cmp(ln.eval(realL), seg[i].eval(realL));
        bool midBetter = cmp(ln.eval(realMid), seg[i].eval(realMid));
        if (midBetter)
            swap(seg[i], ln);
        if (r - l == 1)
            return;
        else if (midBetter != lBetter)
            addLine(ln, 2 * i, l, mid);
        else
            addLine(ln, 2 * i + 1, mid, r);
    }
    ftype query(ftype x, int i, int l, int r) {
        if (r - l == 1)
            return seg[i].eval(x);
        int mid = (l + r) / 2;
        if (x + n < mid)
            return better(query(x, 2 * i, l, mid), seg[i].eval(x));
        else
            return better(query(x, 2 * i + 1, mid, r), seg[i].eval(x));
    }
public:
    void build(int n) { //queries are [-n, n]
        this->n = n;
        Line def(0, neginf);
        seg.assign(8 * n + 5, def);
    }
    void addLine(Line ln) {
        addLine(ln, 1, 0, 2 * n + 1);
    }
    ftype query(ftype x) {
        return query(x, 1, 0, 2 * n + 1);
    }
};

const int sz = 5e5 + 5;
int n, m, k;
vector<pll> adj[sz];
ll di[sz], ndi[sz];

void dijkstra() {
    set<pll> cands;
    foru(i, 0, n)cands.insert({ di[i],i });
    foru(i, 0, n)ndi[i] = di[i];
    vector<bool> done(n, false);
    while (!cands.empty()) {
        auto ii = *cands.begin(); cands.erase(ii);
        ll dist = ii.ff, src = ii.ss;
        if (done[src])continue;
        done[src] = 1;
        for (auto jj : adj[src]) {
            ll dst = jj.ff, w = jj.ss;
            if (ndi[dst] > ndi[src] + w) {
                cands.erase({ ndi[dst],dst });
                ndi[dst] = ndi[src] + w;
                cands.insert({ ndi[dst],dst });
            }
        }
    }
    foru(i, 0, n)di[i] = ndi[i];
}

void build() {
    LiChao lc;
    lc.build(n + 5); //smaller?
    foru(i, 0, n) {
        ll ii = (ll)i;
        ll os = di[i] + ii * ii, sl = -2 * ii;
        lc.addLine(Line(sl, os));
    }
    foru(i, 0, n) {
        chkmin(ndi[i], lc.query(i) + (ll)i * i);
    }
    foru(i, 0, n)di[i] = ndi[i];
}


int main() {
    fast;
    cin >> n >> m >> k;
    foru(i, 0, m) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[--x].push_back({ --y,w });
        adj[y].push_back({ x,w });
    }
    foru(i, 0, n)di[i] = 1e15;
    di[0] = 0;
    foru(j, 0, k) {
        dijkstra();
        build();
    }
    dijkstra();
    foru(i, 0, n) cout << di[i] << ' ';
    return 0;
}