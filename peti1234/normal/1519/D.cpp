#include <bits/stdc++.h>

using namespace std;
const int c=5002;
long long n, a[c], b[c], sum, maxi;
long long csere(int bal, int jobb) {
    //cout << "csere " << bal << " " << jobb << "\n";
    return (a[bal]-a[jobb])*(b[jobb]-b[bal]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        sum+=a[i]*b[i];
    }
    for (int fix=1; fix<=n; fix++) {
        long long ert=0, ert2=0;
        for (int bal=fix, jobb=fix; bal>=1 && jobb<=n; bal--, jobb++) {
            ert+=csere(bal, jobb);
            maxi=max(maxi, ert);
        }
        for (int bal=fix, jobb=fix+1; bal>=1 && jobb<=n; bal--, jobb++) {
            ert2+=csere(bal, jobb);
            maxi=max(maxi, ert2);
        }
    }
    cout << sum+maxi << "\n";
    return 0;
}