#include <bits/stdc++.h>

using namespace std;
int n, b, a, bb, aa, t[200005], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> b >> a;
    bb=b, aa=a;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) {
        if (aa || bb) ans++;
        else break;

        if (aa==a || aa>0 && !t[i] || bb==0) {
            aa--;
        } else {
            bb--;
            if (t[i]) aa++;
        }
    }

    cout << ans << "\n";
    return 0;
}