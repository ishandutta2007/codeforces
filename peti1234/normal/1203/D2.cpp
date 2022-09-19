#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, ans, kezd[c], veg[c];
string a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    n=a.size(), m=b.size();
    for (int i=0; i<n; i++) {
        if (i) kezd[i]=kezd[i-1];
        if (kezd[i]<m && a[i]==b[kezd[i]]) kezd[i]++;
        if (kezd[i]==m) ans=max(ans, n-i-1);
    }
    for (int i=n-1; i>=0; i--) {
        veg[i]=veg[i+1];
        if (veg[i]<m && a[i]==b[m-1-veg[i]]) veg[i]++;
        if (veg[i]==m) ans=max(ans, i);
    }
    int pos=0;
    for (int i=0; kezd[i]<m; i++) {
        while (kezd[i]+veg[pos]>=m) {
            pos++;
        }
        ans=max(ans, pos-i-2);
    }
    cout << ans << "\n";
    return 0;
}