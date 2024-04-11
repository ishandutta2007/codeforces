#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const ll INF = 1e18;
vector<ll> f{1, 1};

void solve() {
    int n, mx = 0;
    cin >> n;
    vector<int> c(n);
    set<pair<ll,ll>> st{{-INF, -INF}};
    ll sum = 0, pr = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
        st.insert({c[i], i});
    }
    if (n == 1 && c[0] == 1) {
        cout << "YES\n";
        return;
    }
    int j = 0;
    while (1) {
        pr += f[j++];
        if (pr >= sum) {
            j--;
            break;
        }
    }
    int last = -1;
    for (int i = j; i >= 0; i--) {
        auto it = prev(st.end());
        if (it->second == last) it--;
        if (it->first < f[i]) {
            cout << "NO\n";
            return;
        }
        pair<int,int> p = *it;
        c[p.second] -= f[i];
        st.erase(p);
        if (c[p.second] > 0) {
            st.insert({c[p.second], p.second});
        }
        last = p.second;
    }
    for (int i = 0; i < n; i++) {
        if (c[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (f.back() < INF) {
        int n = f.size();
        f.pb(f[n - 2] + f[n - 1]);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}