#include <bits/stdc++.h>

using namespace std;
int w, n, k, dif, t[102];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> k >> t[1], dif=0;
        for (int i=2; i<=n; i++) {
            cin >> t[i];
            if (t[i]!=t[i-1]) dif++;
        }
        if (k==1) {
            if (dif==0) cout << 1 << "\n";
            else cout << -1 << "\n";
        } else {
            k--;
            cout << max(1, (dif+k-1)/k) << "\n";
        }
    }
    return 0;
}
// b