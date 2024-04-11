#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(n);
    range(i, n) cin >> x[i];
    vector<char> y(n);
    range(i, n) cin >> y[i];
    vector<int> a, b;
    vector<int> ans(n, -1);
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return x[i] < x[j];
    });
    for(auto &i : ord) {
        if (x[i] & 1) {
            if (y[i] == 'L') {
                if (!a.empty()) {
                    ans[i] = a.back();
                    ans[a.back()] = i;
                    a.pop_back();
                    continue;
                }
                a.push_back(i);
                continue;
            }
            a.push_back(i);
        } else {
            if (y[i] == 'L') {
                if (!b.empty()) {
                    ans[i] = b.back();
                    ans[b.back()] = i;
                    b.pop_back();
                    continue;
                }
                b.push_back(i);
                continue;
            }
            b.push_back(i);
        }
    }
    while(b.size() >= 2) {
        int i = b.back();
        b.pop_back();
        int j = b.back();
        b.pop_back();
        ans[i] = j;
        ans[j] = i;
    }
    while(a.size() >= 2) {
        int i = a.back();
        a.pop_back();
        int j = a.back();
        a.pop_back();
        ans[i] = j;
        ans[j] = i;
    }
    range(i, n) {
        if (ans[i] == -1) {
            cout << "-1 ";
            continue;
        }
        int i1 = i;
        int j1 = ans[i];
        if (x[i1] > x[j1]) swap(i1, j1);
        if (y[i1] == 'R' && y[j1] == 'L') {
            cout << (x[j1] - x[i1]) / 2 << ' ';
            continue;
        }
        if (y[i1] == 'L' && y[j1] == 'L') {
            cout << (x[i1] + x[j1]) / 2 << ' ';
            continue;
        }
        if (y[i1] == 'R' && y[j1] == 'R') {
            cout << (m  * 2 - x[i1] - x[j1]) / 2 << ' ';
            continue;
        }
        if (y[i1] == 'L' && y[j1] == 'R') {
            cout << (m + x[i1] + m - x[j1]) / 2 <<  ' ';
            continue;
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(2) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}