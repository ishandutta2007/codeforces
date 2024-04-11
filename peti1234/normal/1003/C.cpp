#include <bits/stdc++.h>

using namespace std;

long double t[5005], sum, ans, n, k;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        sum=0;
        for (int j=i; j<=n; j++) {
            sum+=t[j];
            if (j-i+1>=k) {
                ans=max(ans, sum/(j-i+1));
            }
        }
    }
    cout.precision(20);
    cout << ans << "\n";
    return 0;
}