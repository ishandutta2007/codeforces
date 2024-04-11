#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

const int N = 755;
const int M = 2e5 + 123;

int n, m;
int a[N];

int calc(ll s) {
    priority_queue<int> q;
    int res = 0;
    
    for (int i = 0; i < n; i++) {
        q.push(-a[i]);
        s += a[i];
        if (s < 0) {
            s += q.top();
            q.pop();
            res++;
        }
    }
    
    return n - res;
}

ll dp[N];

int run() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
            
    for (int val = 0; val <= n; val++) {
        ll left = -1e12;
        ll right = 1e12;
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (calc(mid) >= val) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        dp[val] = right;
    }
    
    for (int i = 0; i < m; i++) {
        ll q;
        cin >> q;
        
        int ans = (int) (upper_bound(dp, dp + n + 1, q) - dp) - 1;
        ans = n - ans;
        cout << ans << "\n";
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}