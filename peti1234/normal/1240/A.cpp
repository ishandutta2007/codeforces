#include <bits/stdc++.h>

using namespace std;
long long w, n, k, t[200005], x, a, y, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            t[i]/=100;
        }
        sort(t+1, t+n+1), reverse(t+1, t+n+1);
        for (int i=2; i<=n; i++) {
            t[i]+=t[i-1];
        }
        cin >> x >> a >> y >> b >> k;
        if (x<y) {
            swap(x, y);
            swap(a, b);
        }
        for (int i=1; i<=n; i++) {
            long long ab=i/(a*b/__gcd(a, b)), aa=i/a, bb=i/a+i/b-ab;
            if (t[ab]*(x+y)+(t[aa]-t[ab])*x+(t[bb]-t[aa])*y>=k) {
                cout << i << "\n";
                break;
            }
            if (i==n) {
                cout << -1 << "\n";
            }
        }

    }
    return 0;
}