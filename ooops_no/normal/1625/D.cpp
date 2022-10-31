#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 3e5 + 10;
int n, k;
vector<int> a(N), ans;

pair<int,int> check(vector<int> b, vector<int> c) {
    vector<vector<int>> go(2, vector<int>(2));
    vector<int> res(2);
    int now = 2;
    for (auto to : b) {
        int u = 1;
        for (int i = 29; i >= 0; i--) {
            int val = 0;
            if (a[to] & (1 << i)) val = 1;
            if (go[u][val] == 0) {
                go.pb(vector<int>(2));
                res.pb(0);
                go[u][val] = now++;
            }
            u = go[u][val];
        }
        res[u] = to;
    }
    int ans = -1;
    pair<int,int> p;
    for (auto to : c) {
        int u = 1, now = 0;
        for (int i = 29; i >= 0; i--) {
            int val = 0;
            if (a[to] & (1 << i)) val = 1;
            if (go[u][val ^ 1] != 0) {
                now += (1 << i);
                u = go[u][val ^ 1];
            } else {
                u = go[u][val];
            }
        }
        if (now > ans) {
            p = {to, res[u]};
            ans = now;
        }
    }
    return p;
}

void solve(vector<int> b, int i, bool good) {
    if (b.size() == 0) return;
    if (i == -1) {
        for (auto to : b) {
            ans.pb(to);
        }
        return;
    }
    vector<int> zero, one;
    for (int j = 0; j < b.size(); j++) {
        if (a[b[j]] & (1 << i)) {
            one.pb(b[j]);
        } else {
            zero.pb(b[j]);
        }
    }

    if (k & (1 << i)) {
        if (zero.size() == 0 || one.size() == 0) {
            if (good) {
                if (zero.size() > 0) ans.pb(zero[0]);
                if (one.size() > 0) ans.pb(one[0]);
            }
            return;
        }
        pair<int,int> p = check(zero, one);
        if ((a[p.first] ^ a[p.second]) >= k) {
            ans.pb(p.first);
            ans.pb(p.second);
        } else {
            if (good) {
                if (zero.size() > 0) ans.pb(zero[0]);
            }
        }
    } else {
        if (one.size() > 0 && zero.size() > 0) good = 1;
        solve(zero, i - 1, good);
        solve(one, i - 1, good);
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    iota(b.begin(), b.end(), 0);
    solve(b, 29, 0);
    if (ans.size() < 2) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (auto to : ans) {
            cout << to + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}