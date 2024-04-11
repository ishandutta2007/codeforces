#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef double ld;
 
const int inf = 1e16; 
const int eps = 1e-6;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    sort(all(a));

    int id = 0;
    for(int i = 0;i < n;i++) {
        while(a[i] - a[id] > 5) 
            id++;

        for(int j = 0;j <= k;j++) {
            dp[i][j] = max(i == 0 ? 0 : dp[i - 1][j], j == 0 ? 0 : (i - id + 1 + (id == 0 ? 0 : dp[id - 1][j - 1])));
        }
    }
    cout << dp[n - 1][k];
}