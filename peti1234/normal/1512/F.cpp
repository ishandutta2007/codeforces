#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, sum, ert, cnt, mini, a[c], b[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> sum;
        ert=0, cnt=0, mini=2e9;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<n; i++) {
            cin >> b[i];
        }
        for (int i=1; i<=n; i++) {
            mini=min(mini, cnt+(sum-ert+a[i]-1)/a[i]);
            long long db=(b[i]-ert+a[i]-1)/a[i];
            cnt+=db+1, ert+=db*a[i];
            ert-=b[i];
        }
        cout << mini << "\n";
    }
    return 0;
}