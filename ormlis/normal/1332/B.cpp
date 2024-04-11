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
const int P = 998244353;
int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> p;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n), used(11, -1);
    int cnt = 1;
    range(i, n) {
        cin >> a[i];
        range(j, 11) {
            if (a[i] % p[j] == 0) {
                if (used[j] == -1) {
                    used[j] = cnt;
                    cnt++;
                }
                c[i] = used[j];
                break;
            }
        }
    }
    cout << cnt - 1 << "\n";
    range(i, n) cout << c[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> d(40, 1);
    for (int i = 2; i < 35; ++i) {
        if (d[i]) {
            p.push_back(i);
            for (int j = i; j < 35; j += i) {
                d[j] = 0;
            }
        }
    }

    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}