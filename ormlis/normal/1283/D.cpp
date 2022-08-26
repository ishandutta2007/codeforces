#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <math.h>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;
#define int ll

int n, m;
set<int> s;

ll check(int d) {
    if (d == 0) return -1;
    int prev = -1300000001;
    int d1 = d - 1;
    int ans = 0;
    ll r = 0;
    for (auto x: s) {
        int cur = 0;
        if (prev != -1300000001) {
            if (x - prev - 1 < d1 * 2) {
                cur = max(min(m - ans, min((x - prev - 1) / 2 + (x - prev - 1) % 2, d1)),1ll* 0);
            } else {
                cur = max(min(m - ans, min(x - prev - 1, d1)), 1ll * 0);
            }
            ans += cur;
            r += 1ll * cur * (cur + 1) / 2;
            if (ans == m) return r;
        }
        if (x != 1300000001) {
            if (x - prev - 1 < d1 * 2) {
                cur = max(min(m - ans, min((x - prev - 1) / 2, d1)), 1ll *0);
            } else {
                cur = max(min(m - ans, min(x - prev - cur - 1, d1)), 1ll * 0);
            }
            ans += cur;
            r += 1ll * cur * (cur + 1) / 2;
            if (ans == m) return r;
        }
        prev = x;
    }
    prev = -1300000001;
    for (auto x: s) {
        if (x - prev - 1 > d1 * 2 && prev != -1300000001) {
            ans++;
            r += 1ll *d;
        }
        if (ans == m) return r;
        if (x - prev - 2 > d1 * 2 && x != 1300000001) {
            ans++;
            r += 1ll* d;
        }
        if (ans == m) return r;
        prev = x;
    }
    return -1;
}

void solve() {
    cin >> n >> m;
    range(i, n) {
        int x;
        cin >> x;
        s.insert(x);
    }
    s.insert(1300000001);
    int r = m;
    int l = 0;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid) != -1) {
            r = mid;
        } else {
            l = mid;
        }
    }
    vector<int> answer;
    int prev = -1300000001;
    int d1 = r - 1;
    int ans = 0;
    ll ra = 0;
    for (auto x: s) {
        int cur = 0;
        if (prev != -1300000001) {
            if (x - prev - 1 < d1 * 2) {
                cur = max(min(m - ans, min((x - prev - 1) / 2 + (x - prev - 1) % 2, d1)), 1ll * 0);
            } else {
                cur = max(min(m - ans, min(x - prev - cur - 1, d1)), 1ll * 0);
            }
            ans += cur;
            for (int i = prev + 1; i <= prev + cur; ++i) {
                answer.push_back(i);
            }
            ra += 1ll * cur * (cur + 1) / 2;
            if (ans == m) break;
        }
        if (x != 1300000001) {
            if (x - prev - 1 < d1 * 2) {
                cur = max(min(m - ans, min((x - prev - 1) / 2, d1)), 1ll * 0);
            } else {
                cur = max(min(m - ans, min(x - prev - cur - 1, d1)), 1ll * 0);
            }
            ans += cur;
            ra += 1ll * cur * (cur + 1) / 2;
            for (int i = x - 1; i >= x - cur; --i) {
                answer.push_back(i);
            }
            if (ans == m) break;
        }
        prev = x;
    }
    prev = -1300000001;
    for (auto x: s) {
        if (ans == m) break;
        if (x - prev - 1 > d1 * 2 && prev != -1300000001) {
            ans++;
            answer.push_back(prev + r);
            ra += 1ll *r;
        }
        if (ans == m) break;
        if (x - prev - 2 > d1 * 2 && x != 1300000001) {
            ans++;
            ra += 1ll * r;
            answer.push_back(x - r);
        }
        if (ans == m) break;
        prev = x;
    }
    cout << ra << '\n';
    for (auto u: answer) {
        cout << u << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}