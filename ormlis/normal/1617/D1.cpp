#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    auto ask = [&](int a, int b, int c) {
        cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        int r;
        cin >> r;
        return r;
    };
    vector<int> ans(n, -1);
    vector<int> to(n / 3);
    // n / 3
    rep(i, n / 3) {
        to[i] = ask(i * 3, i * 3 + 1, i * 3 + 2);
    }
    int L = 0;
    int R = 1;
    while (to[R] == to[L]) R++;
    if (to[L] == 1) swap(L, R);
    rep(i, 2) {
        int x = L * 3 + (i + 1) % 3;
        int y = L * 3 + (i + 2) % 3;
        int w = 0;
        rep(j, 3) {
            int z = R * 3 + j;
            int res = ask(x, y, z);
            if (res == 1) {
                ans[z] = 1;
                w = 1;
            }
        }
        if (w == 0) {
            ans[x] = ans[y] = 0;
        }
    }
    int ct = 0;
    rep(i, 3) {
        int x = L * 3 + i;
        if (ans[x] == -1) {
            ct++;
        }
    }
    if (ct == 3) {
        ans[L * 3 + 2] = 1;
        ans[L * 3] = 0;
        ans[L * 3 + 1] = 0;
    } else {
        rep(i, 3) {
            if (ans[L * 3 + i] == -1) {
                ans[L * 3 + i] = 1;
            }
        }
    }
    ar<int, 2> g = {-1, -1};
    rep(i, 3) {
        g[ans[L * 3 + i]] = L * 3 + i;
    }
    auto upd = [&] (int i) {
        if (to[i] == 1) {
            int k = g[0];
            int t = ask(i * 3, i * 3 + 1, k);
            int d = ask(i * 3, i * 3 + 2, k);
            if (t == 0 && d == 0) {
                ans[i * 3] = 0;
                ans[i * 3 + 1] = 1;
                ans[i * 3 + 2] = 1;
            } else if (t == 1 && d == 1) {
                ans[i * 3] = ans[i * 3 + 1] = ans[i * 3 + 2] = 1;
            } else if (d == 1) {
                ans[i * 3] = ans[i * 3 + 2] = 1;
                ans[i * 3 + 1] = 0;
            } else if (t == 1) {
                ans[i * 3] = ans[i * 3 + 1] = 1;
                ans[i * 3 + 2] = 0;
            }
        } else {
            int k = g[1];
            int t = ask(i * 3, i * 3 + 1, k);
            int d = ask(i * 3, i * 3 + 2, k);
            if (t == 1 && d == 1) {
                ans[i * 3] = 1;
                ans[i * 3 + 1] = 0;
                ans[i * 3 + 2] = 0;
            } else if (t == 0 && d == 0) {
                ans[i * 3] = ans[i * 3 + 1] = ans[i * 3 + 2] = 0;
            } else if (d == 0) {
                ans[i * 3] = ans[i * 3 + 2] = 0;
                ans[i * 3 + 1] = 1;
            } else if (t == 0) {
                ans[i * 3] = ans[i * 3 + 1] = 0;
                ans[i * 3 + 2] = 1;
            }
        }
    };
    upd(R);
    rep(i, 3) {
        g[ans[R * 3 + i]] = R * 3 + i;
    }
    rep(i, n / 3) {
        if (i == L || i == R) continue;
        upd(i);
    }
    vector<int> answ;
    rep(i, n) {
        if (ans[i] == 0) {
            answ.push_back(i + 1);
        }
    }
    cout << "! ";
    cout << answ.size() << ' ';
    for(auto &x : answ) cout << x << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}