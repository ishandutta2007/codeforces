#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, n, a, b, p[c], h[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b >> n;
        maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            maxi=max(maxi, p[i]);
        }
        for (int i=1; i<=n; i++) {
            cin >> h[i];
        }
        for (int i=1; i<=n; i++) {
            long long s=(h[i]+a-1)/a;
            b-=p[i]*s;
        }
        cout << (b+maxi>0 ? "YES" : "NO") << "\n";
    }
    return 0;
}