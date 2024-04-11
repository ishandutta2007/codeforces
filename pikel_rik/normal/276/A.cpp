#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e8;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<ll> f(n), t(n);
    for (int i = 0; i < n; i++) cin >> f[i] >> t[i];

    ll best = INT_MIN;
    for (int i = 0; i < n; i++) {
        best = max(best, f[i] - (t[i] <= k ? 0 : (t[i] - k)));
    }

    cout << best << "\n";
    return 0;

}