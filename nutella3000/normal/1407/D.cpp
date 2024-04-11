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
const int max_n = 3e5 + 2;
int n;
int a[max_n];
int big[max_n], small[max_n];

void scan() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = n - 1;i >= 0;i--) {
        int v = i + 1;
        while(v != n) {
            if (a[v] > a[i]) break;
            v = big[v];
        }
        big[i] = v;
        v = i + 1;
        while(v != n) {
            if (a[v] < a[i]) break;
            v = small[v];
        }
        small[i] = v;
    }
}

void solve() {
    scan();
    vector<int> dp(max_n);
    for(int i = n - 2;i >= 0;i--) {
        dp[i] = dp[i + 1] + 1;

        int v = i + 1;
        if (a[i + 1] < a[i]) {
            while(v != n) {
                dp[i] = min(dp[i], dp[v] + 1);
                if (a[v] >= a[i]) break;
                v = big[v];
            }
        }else if (a[i + 1] > a[i]) {
            while(v != n) {
                dp[i] = min(dp[i], dp[v] + 1);
                if (a[v] <= a[i]) break;
                v = small[v];
            }
        }
    }

    cout << dp[0];
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}