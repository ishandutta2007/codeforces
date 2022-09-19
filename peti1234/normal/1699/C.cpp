#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, ans, inv[c], mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            inv[x]=i;
        }
        int kis=n+1, nagy=0;
        ans=1;
        for (int i=0; i<n; i++) {
            int pos=inv[i];
            if (pos<kis || pos>nagy) {
                nagy=max(nagy, pos);
                kis=min(kis, pos);
            } else {
                ans=ans*(nagy-kis+1-i)%mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}