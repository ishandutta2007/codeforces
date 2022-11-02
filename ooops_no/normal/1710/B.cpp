#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int INF = 2e9;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), p(n), ord(n), ans(n);
        vector<ll> val(n), mx(n);
        multiset<ll> L, R, R_del;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> p[i];
            R.insert(p[i] - x[i]);
        }
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){return x[i] < x[j];});
        ll sum = 0, cnt = 0;
        for (auto i : ord) {
            //x[i], p[i];
            sum += x[i] + p[i];
            sum -= p[i] - x[i];
            cnt--;
            L.insert(x[i] + p[i]);
            while (L.size() > 0 && *L.begin() < x[i]) {
                sum -= *L.begin();
                L.erase(L.find(*L.begin()));
            }
            while (R.size() > 0 && *R.rbegin() + x[i] > 0) {
                sum += *R.rbegin();
                cnt++;
                R.erase(R.find(*R.rbegin()));
            }
            ll result = sum + cnt * x[i] - (ll)(L.size()) * x[i];
            val[i] = result;
        }
        ll last = -1, mx_val = -INF;
        for (auto i : ord) {
            mx_val += x[i] - last;
            last = x[i];
            if (val[i] > m) {
                mx_val = max(mx_val, val[i] - m);
            }
            mx[i] = max(mx_val, mx[i]);
        }
        reverse(ord.begin(), ord.end());
        last = -1, mx_val = -INF;
        for (auto i : ord) {
            mx_val += last - x[i];
            last = x[i];
            if (val[i] > m) {
                mx_val = max(mx_val, val[i] - m);
            }
            mx[i] = max(mx_val, mx[i]);
        }
        for (auto i : ord) {
            if (mx[i] <= p[i]) {
                ans[i] = 1;
            }
        }
        for (auto to : ans) {
            cout << to;
        }
        cout << endl;
    }
    return 0;
}