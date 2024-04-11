#include <bits/stdc++.h>
 
using namespace std;
long long n, sum, maxi, x;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        maxi=max(maxi, x);
        sum+=x;
    }
    cout << (sum%2 || 2*maxi>sum ? "NO" : "YES") << "\n";
    return 0;
}