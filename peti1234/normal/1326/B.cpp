#include <bits/stdc++.h>

using namespace std;
long long n, maxi=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        cout << x+maxi << " ";
        maxi=max(maxi, x+maxi);
    }
    return 0;
}