#include <bits/stdc++.h>

using namespace std;
long long n, k, x;
long double sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (long long i=1; i<=n; i++) {
        cin >> x;
        sum+=min({i, n-k+1, k, n+1-i})*x;
    }
    cout.precision(10);
    cout << sum/(n-k+1) << "\n";
    return 0;
}