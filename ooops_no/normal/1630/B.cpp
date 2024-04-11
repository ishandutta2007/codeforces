#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b = a;
        sort(a.begin(), a.end());
        vector<pair<int,int>> u;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                u.pb({a[i - 1], i});
            }
        }
        u.pb({a.back(), n});
        int ans = INF;
        pair<int,int> p;
        for (int i = 0; i < u.size(); i++) {
            int a = 0;
            if (i > 0) a = u[i - 1].second;
            if (u.back().second - a < a + k) {
                break;
            }
            int l = i - 1, r = u.size();
            while (r - l > 1) {
                int mid = (r + l) / 2;
                if (u[mid].second - a >= a + k + n - u[mid].second) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            if (ans > u[r].first - u[i].first) {
                ans = u[r].first - u[i].first;
                p = {u[i].first, u[r].first};
            }
        }
        cout << p.first << ' ' << p.second << endl;
        int last = 1, cnt = 0, need = k;
        for (int i = 0; i < n; i++) {
            if (p.first <= b[i] && b[i] <= p.second) {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt > 0 && need > 1) {
                cout << last << ' ' << i + 1 << endl;
                last = i + 2;
                cnt = 0;
                need--;
            }
        }
        cout << last << ' ' << n << endl;
    }
    return 0;
}