#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
typedef long long LL;

int n;
int c[N];
string s[N][2];

LL dp[N][2];
LL f(int x, bool rev) {
    if (x > n) return 0;
    
    LL &ret = dp[x][rev];
    if (~ret) return ret;
    
    ret = 1000000000000000LL;
    
    if (s[x][0] >= s[x-1][rev]) ret = min(ret, f(x+1, 0));
    if (s[x][1] >= s[x-1][rev]) ret = min(ret, f(x+1, 1) + c[x]);
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    s[0][0] = s[0][1] = "$";    
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> c[i];
    for (int i=1; i<=n; i++) {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        
        reverse (s[i][1].begin(), s[i][1].end());
    }
    
    memset (dp, -1, sizeof dp);
    if (f(1, 0) == 1000000000000000LL) cout << -1 << endl;
    else cout << f(1, 0) << endl;
    
    return 0;
}