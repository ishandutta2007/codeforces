#include <bits/stdc++.h>

using namespace std;
const int c=15000005;
int n, lnko, db[c], t[c], pr[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        lnko=__gcd(lnko, t[i]);
    }
    for (int i=1; i<=n; i++) {
        db[t[i]/lnko]++;
    }
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            int sum=0;
            for (int j=i; j<c; j+=i) {
                sum+=db[j];
                pr[j]=1;
            }
            maxi=max(maxi, sum);
        }
    }
    cout << (maxi ? n-maxi : -1) << "\n";
    return 0;
}