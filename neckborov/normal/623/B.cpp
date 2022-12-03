#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int n;
ll a, b;
ll ans = LLONG_MAX;

void solve(vector<int>& c, ll z = 0) {
    vector<int> divs;
    int x = c[0];
    for (int i = 2; i * i <= c[0]; i++) {
        if (x % i == 0) {
            divs.push_back(i);
        }
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x > 1) {
        divs.push_back(x);
    }
    for (int i : divs) {
        ll cost = 0;
        int cnt_l = 0;
        int cnt_r = 0;
        int left = -1, right = -2;
        for (int j = 1; j < n; j++) {
            int dist = c[j] % i;
            dist = min(dist, i - dist);
            if (dist == 1) {
                if (left == -1) {
                    cnt_l++;
                }
                cnt_r++;
            }
            if (dist > 1) {
                if (left == -1) {
                    left = j;
                    right = j;
                } else {
                    right = j;
                }
                cnt_r = 0;
            }
        }
        if (left == -1) {
            cnt_r = 0;
        }
        cost += (right - left + 1) * a + (cnt_l + cnt_r) * b;
        ll best = 0;
        int t = 0;
        if (right >= 0) {
            for (int j = right + 1; j < n; j++) {
                if (c[j] % i == 0) {
                    continue;
                } 
                t++;
                best = min(best, a * (j - right) - b * t);
            }
            cost += best;
            best = t = 0;
            for (int j = left - 1; j > 0; j--) {
                if (c[j] % i == 0) {
                    continue;
                } 
                t++;
                best = min(best, a * (left - j) - b * t);
            }
            cost += best;
        } else {
            ll kek = -1e15;
            for (int j = 1; j < n; j++) {
                if (c[j] % i == 0) {
                    continue;
                }
                t++;
                kek = max(kek, a * j - b * t);
                best = min(best, a * (j + 1) - b * (t + 1) - kek);
            }
            cost += best;
        }
        ans = min(ans, cost + z);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> a >> b;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    solve(c);
    c[0]--;
    solve(c, b);
    c[0] += 2;
    solve(c, b);
    c[0]--;
    reverse(c.begin(), c.end());
    solve(c);
    c[0]--;
    solve(c, b);
    c[0] += 2;
    solve(c, b);
    cout << ans;
    return 0;
}