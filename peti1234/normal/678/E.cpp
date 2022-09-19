#include <bits/stdc++.h>

using namespace std;
const int c=18;
int n;
double dp[1<<c][c], t[c][c], ans;
bool v[1<<c][c];
double solve(int a, int b) {
    if (v[a][b]) {
        return dp[a][b];
    }
    if (__builtin_popcount(a)==n-1) {
        if (b==0) {
            return 1;
        }
        return 0;
    }
    double res=0;
    for (int j=0; j<n; j++) {
        if (j!=b && !(a&(1<<j))) {
            res=max(res, solve(a+(1<<j), b)*t[b][j]+solve(a+(1<<b), j)*t[j][b]);
        }
    }
    v[a][b]=1;
    return dp[a][b]=res;
}
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        ans=max(ans, solve(0, i));
    }
    cout.precision(10);
    cout << ans << "\n";
    return 0;
}