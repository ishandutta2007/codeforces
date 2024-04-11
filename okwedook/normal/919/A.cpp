#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    double ans = 1e18;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        ans = min(ans, m * a / b);
    }
    cout << fixed << setprecision(10) << ans;
    //system("pause");
    return 0;
}