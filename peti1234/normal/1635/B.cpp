#include <bits/stdc++.h>

using namespace std;
int n, w, ans, t[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=2; i<n; i++) {
            if (t[i]>t[i-1] && t[i]>t[i+1]) {
                t[i+1]=max(t[i], t[i+2]);
                ans++;
            }
        }


        cout << ans << "\n";
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
        ans=0;
        for (int i=1; i<=n; i++) {
            t[i]=0;
        }
    }
    return 0;
}