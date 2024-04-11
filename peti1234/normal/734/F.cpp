#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=32;
int t[c], a[c], b[c], n;
long long sum, bit[k];
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], sum+=a[i];
    for (int i=1; i<=n; i++) cin >> b[i], sum+=b[i];
    if (sum%(2*n)) baj=1;
    sum/=2*n;
    for (int i=1; i<=n; i++) {
        t[i]=(a[i]+b[i]-sum)/n;
        if ((t[i]*n)!=a[i]+b[i]-sum) baj=1;
        long long x=t[i];
        for (int j=0; j<k; j++) {
            bit[j]+=x%2;
            x/=2;
        }
    }
    for (int i=1; i<=n; i++) {
        long long x=t[i], ert=0;
        for (int j=0; j<k; j++) {
            if (x%2) ert+=bit[j]*(1<<j);
            x/=2;
        }
        if (ert!=a[i]) baj=1;
    }
    if (baj) cout << -1;
    else for (int i=1; i<=n; i++) cout << t[i] << " ";
    cout << "\n";
    return 0;
}