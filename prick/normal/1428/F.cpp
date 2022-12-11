//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

const int tsize = 1 << 19;

int tree[2 * tsize];

void push(int v) {
    if (v < tsize) {
        tree[v * 2] += tree[v];
        tree[v * 2 + 1] += tree[v];
        tree[v] = 0;
    }
}

void add(int left, int right, int v, int tl, int tr) {
    push(v);
    if (right < tl || left > tr) {
        return;
    }
    if (left <= tl && tr <= right) {
        ++tree[v];
        return;
    }
    int tm = (tl + tr) / 2;
    add(left, right, v * 2, tl, tm);
    add(left, right, v * 2 + 1, tm + 1, tr);
}

void setval(int pos, int value, int v, int tl, int tr) {
    push(v);
    if (pos < tl || pos > tr) {
        return;
    }
    if (tl == tr) {
        tree[v] = value;
        return;
    }
    int tm = (tl + tr) / 2;
    setval(pos, value, v * 2, tl, tm);
    setval(pos, value, v * 2 + 1, tm + 1, tr);
}

int get(int pos, int v, int tl, int tr) {
    push(v);
    if (pos < tl || pos > tr) {
        return 0;
    }
    if (tl == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return get(pos, v * 2, tl, tm) + get(pos, v * 2 + 1, tm + 1, tr);
}

int getDiff(int pos) {
    if (pos == 0) {
        return 0;
    }
    int A = get(pos - 1, 1, 0, tsize - 1);
    int B = get(pos, 1, 0, tsize - 1);
    return (B - A) * pos;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int global_ans = 0;
    int ans_suf = 0;
    int ones = 0;
    for (auto ch: s) {
        if (ch == '0') {
            ones = 0;
            add(0, tsize - 1, 1, 0, tsize - 1);
        } else {
            ++ones;
            ans_suf -= getDiff(ones - 1);
            ans_suf -= getDiff(ones);
            setval(ones - 1, ones - 1, 1, 0, tsize - 1);
            add(ones, tsize - 1, 1, 0, tsize - 1);
            ans_suf += getDiff(ones - 1);
            ans_suf += getDiff(ones);
        }
        //cerr << ans_suf << endl;
        global_ans += ans_suf;
    }
    cout << global_ans << '\n';
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}