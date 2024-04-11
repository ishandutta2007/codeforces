#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i] >> b[i];
    vector<int> c(2 * n);
    vector<int> p(2 * n);
    vector<int> cost(2 * n);
    range(i, n) {
        a[i]--;
        b[i]--;
        p[a[i]] = b[i];
        p[b[i]] = a[i];
        cost[b[i]] = 1;
    }
    int l = 0, r = 2 * n - 1;
    int ans = 0;
    vector<int> cur(2 * n, -1);
    while(r > l) {
        int l1 = l;
        int r1 = r;
        int needr = r;
        int needl = l + 1;
        while(l < needl || r > needr) {
            if (needl - needr > 1) break;
            if (l < needl) {
                if (cur[l] == -1)  {
                    cur[l] = 0;
                    cur[p[l]] = 1;
                }
                needr = min(needr, p[l++] - 1);
            } else if (r > needr) {
                if (cur[r] == -1)  {
                    cur[r] = 0;
                    cur[p[r]] = 1;
                }
                needl = max(needl, p[r--] + 1);
            }
        }
        if (needl - needr > 1) {
            cout << "-1\n";
            return;
        }
        int cnt = needl - l1;
        int price = 0;
        vector<int> ord1;
        for(int i = l1; i < needl; ++i) {
            if (cur[i] == 0) ord1.push_back(p[i]);
            price += (cost[i] ^ cur[i]);
        }
        for(int i = needr + 1; i <= r1; ++i) {
            if (cur[i] == 0) ord1.push_back(p[i]);
        }
        vector<int> ord2;
        for(int i = l1; i < needl; ++i) {
            if (cur[i] == 1) ord2.push_back(i);
        }
        for(int i = needr + 1; i <= r1; ++i) {
            if (cur[i] == 1) ord2.push_back(i);
        }
        reverse(all(ord2));
        if (ord1 != ord2) {
            cout << "-1\n";
            return;
        }
        ans += min(price, cnt - price);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}