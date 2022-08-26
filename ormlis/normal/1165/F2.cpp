#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m; cin >> n >> m;
    vector<int> k(n);
    range(i, n) cin >> k[i];
    vector<vector<int>> sel(n);
    range(i, m) {
        int d, t; cin >> d >> t;
        sel[t-1].push_back(d);
    }
    range(i, n) sort(all(sel[i]));

    auto check = [&] (int day) {
        auto need = k;
        vector<pair<int, int>> current;
        range(i, n) {
            auto w = upper_bound(all(sel[i]), day);
            if (w != sel[i].begin()) current.emplace_back(*prev(w), i);
        }
        sort(all(current));
        int money = 0, curday = 0;
        for(auto &x: current) {
            money += x.first - curday;
            curday = x.first;
            int get = min(need[x.second], money);
            money -= get;
            need[x.second] -= get;
        }
        money += day - curday;
        range(i, n) money -= need[i] * 2;
        return money >= 0;
    };

    int l = 0, r = 4e5 + 100;
    while(r - l > 1) {
        int mid = (r + l) /2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}