#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 97

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i;
    ios::sync_with_stdio(false);
    double ans = 1e16;
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        double a, b;
        cin >> a >> b;
        ans = min(ans, 1.0 * m * (a / b));
    }
    cout << setprecision(20) << ans;
    //cin.close();
    //cout.close();
    return 0;
}