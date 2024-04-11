#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    if (n < 100) {
        int answer = INFi;
        range(i, n) {
            int x = a[i];
            for(int j = i - 1; j >= 0; --j) {
                x ^= a[j];
                if (j && a[j - 1] > x) answer = min(answer, i - j);
                if (i + 1 != n && a[i + 1] < x) answer = min(answer, i - j);
                int x2 = 0;
                for(int e = j - 1; e >= 0; --e) {
                    x2 ^= a[e];
                    if (x2 > x) answer = min(answer, i - e - 1);
                }
            }
        }
        if (answer == INFi) {
            cout << "-1\n";
        } else {
            cout << answer;
        }
        return;
    }
    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}