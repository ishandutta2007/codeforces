#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;
typedef long double ld;

using namespace std;

const int maxN = 1e7 + 5;
const int INFi = 2e9;
const ll INF = 1e18;

void solve() {
    int a, b, k; cin >> a >> b >> k;
    vector<int> num1(a + b), num2(a + b);
    num1[0] = num2[0] = 1;
    if (k > a + b - 2 && k != 0) {
        cout << "No\n";
        return;
    }
    if (k != 0 && (b == 1 || a == 0)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int c = b;
    c--;
    if (c) {
        num1[1] = 1;
        num2[1 + k] = 1;
        c--;
        for (int i = 2; i < a + b; ++i) {
            if (i == 1 + k) continue;
            if (!c) break;
            num1[i] = num2[i] = 1;
            c--;
        }
    }
    range(i, a + b) cout << num1[i];
    cout << '\n';
    range(i, a + b) cout << num2[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}