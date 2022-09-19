#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int t[c], kezd[c], veg[c], n, maxi;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]>t[i-1]) veg[i]=veg[i-1]+1;
        else veg[i]=1;
        maxi=max(maxi, veg[i]);
    }
    for (int i=n; i>=1; i--) {
        if (t[i]<t[i+1]) kezd[i]=kezd[i+1]+1;
        else kezd[i]=1;
    }
    for (int i=2; i<n; i++) {
        if (t[i-1]<t[i+1]) maxi=max(maxi, veg[i-1]+kezd[i+1]);
    }

    cout << maxi << "\n";
    return 0;
}