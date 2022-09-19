#include <bits/stdc++.h>

using namespace std;
long double ans, e=1;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        ans+=e/i;
    }
    cout.precision(20);
    cout << ans << "\n";
    return 0;
}