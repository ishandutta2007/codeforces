#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 1e5 + 1;
const int md = 1e9 + 7;

const int K = 300;

int n;
int b[maxN];
int bl[maxN];

struct fenwick {
    int n{};
    vector<int> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, int x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    int get(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }

    void clear(vector<int> &was) {
        for(auto &x : was) {
            upd(x, -1);
        }
    }
} F;

// K log N
void rebuild(int block) {
    int l = block * K;
    int r = min(l + K, n);
    vector<int> res;
    for(int i = l; i < r; ++i) {
        if (res.empty()) {
            res.push_back(b[i]);
            F.upd(b[i], 1);
            continue;
        }
        int cur = -1;
        int ad = 0;
        for(int j = 18; j >= 0; --j) {
            int t = 1 << j;
            if (cur + t < n && cur + t + F.fenw[cur + t] + ad < b[i]) {
                cur += t;
                ad += F.fenw[cur];
            }
        }
        cur++;
        res.push_back(cur);
        F.upd(cur, 1);
    }
    F.clear(res);
    sort(all(res));
    for(int i = l; i < r; ++i) {
        bl[i] = res[i - l];
    }
}

void upd(int i, int x) {
    b[i] = x;
    b[i] = i - b[i];
    rebuild(i / K);
}


// N / K log N
int get(int i) {
    int bq = i / K;
    int r = min((bq + 1) * K, n);
    int to = b[i];
    for(int j = i + 1; j < r; ++j) {
        if (b[j] <= to) to++;
    }
    int l = bq * K;
    for(int j = bq + 1; j * K < n; ++j) {
        r += K;
        l += K;
        if (r > n) r = n;
        int c = (int)(upper_bound(bl + l, bl + r, to) - (bl + l));
        to += c;
    }
    return to;
}

void solve() {
    cin >> n;
    F.build(n + 5);
    range(i, n) {
        cin >> b[i];
        b[i] = i - b[i];
    }
    for(int j = 0; j * K < n; ++j) {
        rebuild(j);
    }
    int q; cin >> q;
    range(_, q) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x;
            i--;
            upd(i, x);
        } else {
            int i; cin >> i;
            i--;
            cout << get(i) + 1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}