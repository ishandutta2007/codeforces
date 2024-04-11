#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, a[c], b[c], x[c], y[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> x[i] >> y[i];
            a[x[i]]++, b[y[i]]++;
        }
        ans=n*(n-1)*(n-2)/6;
        for (int i=1; i<=n; i++) {
            ans-=(a[x[i]]-1)*(b[y[i]]-1);
        }
        cout << ans << "\n";
        ans=0;
        for (int i=1; i<=n; i++) {
            a[i]=b[i]=x[i]=y[i]=0;
        }
    }
    return 0;
}