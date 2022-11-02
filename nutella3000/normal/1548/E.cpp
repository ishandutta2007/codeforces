#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
const int max_n = (1 << 18);

int n, m, x;
int a[max_n], b[max_n], mna[max_n], mnb[max_n];

void f(int a[], int n, int mn[]) {
    fill(mn, mn + n, 0);

    deque<int> d1, d2;
    for (int i = n - 1; i >= 0; --i) {
        while (size(d2) && a[d2.back()] <= a[i]) d2.pop_back();
        while (size(d1) && a[d1.back()] >= a[i]) d1.pop_back();

        d2.pb(i);
        if (size(d1)) {
            while (size(d2) > 1 && d2[size(d2) - 2] < d1.back()) d2.pop_back();
            mn[i] = x + 1 - a[d2.back()];
        }
        d1.pb(i);
    }
    d1.clear(); d2.clear();

    for (int i = 0; i < n; ++i) {
        while (size(d2) && a[d2.back()] <= a[i]) d2.pop_back();
        while (size(d1) && a[d1.back()] > a[i]) d1.pop_back();

        d2.pb(i);
        if (size(d1)) {
            while (size(d2) > 1 && d2[size(d2) - 2] > d1.back()) d2.pop_back();
            chkmax(mn[i], x + 1 - a[d2.back()]);
        }
        d1.pb(i);
    }
}

int sum[2 * max_n];

void segadd(int id) {
    for (id += max_n; id; id >>= 1) ++sum[id];
}

int segget(int l, int r) {
    int res = 0;
    for (l += max_n, r += max_n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += sum[l++];
        if (r & 1) res += sum[--r];
    }
    return res;
}

void run() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    f(a, n, mna);
    f(b, m, mnb);

    int res = 0;

    vector<int> id1(n), id2(m);
    iota(all(id1), 0), iota(all(id2), 0);
    sort(all(id1), [](int v1, int v2) { return a[v1] < a[v2]; });
    sort(all(id2), [](int v1, int v2) { return mnb[v1] < mnb[v2]; });

    int ind = 0;
    for (int i = 0; i < n; ++i) {
        int va = a[id1[i]], vm = mna[id1[i]];
        while (ind < m && mnb[id2[ind]] <= va) segadd(b[id2[ind++]]);
        res += segget(max(vm, 0ll), x - va + 1);
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] + b[j] <= x && a[i] >= mnb[j] && b[j] >= mna[i]) {
                ++res;
            }
        }
    }*/
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}