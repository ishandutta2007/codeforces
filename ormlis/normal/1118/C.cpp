#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    range(i, n * n) {
        int x; cin >> x;
        mp[x]++;
    }

    vector<vector<int>> t(n, vector<int> (n));
    range(i, n / 2) {
        range(j, n / 2) {
            for(auto &x: mp) {
                if (x.second >= 4) {
                    x.second -= 4;
                    t[i][j] = t[n-1-i][j] = t[i][n-1-j] = t[n-1-i][n-1-j] = x.first;
                    break;
                }
            }
            if (!t[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    if (n % 2) {
        int mid = n / 2;
        range(i, mid) {
            for(auto &x: mp) {
                if (x.second >= 2) {
                    x.second -= 2;
                    t[i][mid] = t[n-1-i][mid] = x.first;
                    break;
                }
            }
            for(auto &x: mp) {
                if (x.second >= 2) {
                    x.second -= 2;
                    t[mid][i] = t[mid][n-1-i] = x.first;
                    break;
                }
            }
            if (!t[i][mid] || !t[mid][i]) {
                cout << "NO\n";
                return;
            }
        }
        for(auto &x: mp) {
            if (x.second) {
                t[mid][mid] = x.first;
                break;
            }
        }
    }
    cout << "YES\n";
    range(i, n) {
        range(j, n) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
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