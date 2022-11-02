#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 2e5 + 10;
int cnt[N], del[N];
vector<int> add[N];
vector<pair<int,int>> need[N], deg[N];

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

struct Fenwick {
    vector<ll> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void inc(int i, int d) {
        for (; i < t.size(); i = (i | (i + 1))) {
            t[i] += d;
        }
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += t[r];
        }
        return ans;
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Fenwick F(N), F_cnt(N);
    for (int i = 1; i < N; i++) {
        set<int> st;
        for (int j = 1; j * j <= i * 2; j++) {
            if (i * 2 % j == 0) {
                if (j < i) st.insert(j);
                if (i * 2 / j < i) st.insert(i * 2 / j);
            }
        }
        cnt[i] = st.size();
        for (auto to : st) {
            add[to].pb(i);
        }
        vector<int> mas1, mas2, mas3;
        for (auto to : st) {
            if (i % to != 0) {
                mas1.pb(to);
            } else {
                mas3.pb(to);
            }
            mas2.pb(to);
        }
        int j = (int)(mas2.size()) - 1, cur = 0, res = 0;
        for (int f = 0; f < mas1.size(); f++) {
            while (j >= 0 && mas1[f] + mas2[j] > i) {
                j--;
            }
            if (j >= 0 && mas2[j] > mas1[f]) {
                int ind = upper_bound(mas2.begin(), mas2.end(), mas1[f]) - mas2.begin();
                res += j - ind + 1;
                deg[mas1[f]].pb({i, j - ind + 1});
            }
        }
        j = (int)(mas1.size()) - 1;
        for (int f = 0; f < mas3.size(); f++) {
            while (j >= 0 && mas3[f] + mas1[j] > i) {
                j--;
            }
            if (j >= 0 && mas1[j] > mas3[f]) {
                int ind = upper_bound(mas1.begin(), mas1.end(), mas3[f]) - mas1.begin();
                res += j - ind + 1;
                deg[mas3[f]].pb({i, j - ind + 1});
            }
        }
        del[i] = res;
        F.inc(i, del[i]);
    }
    int t;
    cin >> t;
    vector<ll> ans(t);
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        need[l].pb({r, i});
    }
    for (int i = 1; i < N; i++) {
        F_cnt.inc(i, (ll)(cnt[i]) * (cnt[i] - 1) / 2);
    }
    for (int i = 1; i < N; i++) {
        for (auto to : need[i]) {
            ll res = 0, len = to.first - i + 1;
            res += F_cnt.get(to.first);
            res -= F.get(to.first);
            ans[to.second] = len * (len - 1) * (len - 2) / 6 - res;
        }
        for (auto to : add[i]) {
            F_cnt.inc(to, (ll)-cnt[to] * (cnt[to] - 1) / 2);
            cnt[to]--;
            F_cnt.inc(to, (ll)cnt[to] * (cnt[to] - 1) / 2);
        }
        for (auto to : deg[i]) {
            F.inc(to.first, -to.second);
        }
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}