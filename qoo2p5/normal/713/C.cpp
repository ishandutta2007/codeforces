#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()

const int INF = 1e9 + 1;
const ll LINF = 1e18 + 1;

const int N = 3003;

int n;
ll a[N];
ll v[N];
ll dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i] = a[i] - i;
    }
    
    sort(v, v + n);
    
    for (int i = 0; i < n; i++) {
        fill(dp[i], dp[i] + n, LINF);
        dp[0][i] = min(i == 0 ? LINF : dp[0][i - 1], abs(a[0] - v[i]));
    }
    
    for (int i = 1; i < n; i++) {
        int ptr = -1;
        
        for (int j = 0; j < n; j++) {
            while (ptr + 1 < n && v[ptr + 1] + (i - 1) < v[j] + i) {
                ptr++;
            }
            
            if (ptr != -1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][ptr] + abs(a[i] - (v[j] + i)));
            }
            
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[n - 1][n - 1] << "\n";
    
	return 0;
}