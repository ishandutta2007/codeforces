#include <bits/stdc++.h>

using namespace std;
long long t, n, sum=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n, sum=0;
        for (int i=1; i<n/2; i++) sum+=(1<<i);
        for (int i=n/2; i<n; i++) sum-=(1<<i);
        sum+=(1<<n);
        cout << sum << "\n";
    }
    return 0;
}