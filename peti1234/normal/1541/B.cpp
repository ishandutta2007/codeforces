#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int w, n, t[c], inv[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=2*n; i++) {
            inv[i]=0;
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            inv[t[i]]=i;
        }
        int ans=0;
        for (long long a=1; a<=2*n; a++) {
            for (long long b=a+1; a*b<=2*n; b++) {
                if (inv[a] && inv[b] && inv[a]+inv[b]==a*b) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}