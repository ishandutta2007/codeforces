#include <bits/stdc++.h>

using namespace std;
long long a[100002], b[100002], n, m, suma, sumb, maxa, maxb, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        suma+=a[i];
        maxa=max(maxa, a[i]);
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
        sumb+=b[i];
        maxb=max(maxb, b[i]);
    }
    if (maxa>=maxb) {
        ans=sumb;
        for (int i=1; i<=n; i++) {
            ans+=min(a[i], sumb);
        }
        ans-=min(maxa, sumb);
    } else {
        ans=suma;
        for (int i=1; i<=m; i++) {
            ans+=min(b[i], suma);
        }
        ans-=min(maxb, suma);
    }
    cout << ans << "\n";
    return 0;
}