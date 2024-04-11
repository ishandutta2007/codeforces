#include <bits/stdc++.h>

using namespace std;
int n, m, sum, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum+=x;
        maxi=max(maxi, x);
    }
    cout << max(maxi, (sum+m+n-1)/n) << " " << maxi+m << "\n";
    return 0;
}