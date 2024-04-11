#include <bits/stdc++.h>

using namespace std;
long long w, n, k, s=0, t[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k, s=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        for (int i=2; i<=n; i++) {
            s=__gcd(s, t[i]-t[i-1]);
        }
        cout << (((s==0 && k!=t[1]) || (s && (k-t[1])%s)) ? "NO" : "YES") << "\n";
    }
    return 0;
}