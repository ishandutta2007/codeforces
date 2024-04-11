#include <bits/stdc++.h>

using namespace std;
int n, r, t[1005], s[1005], cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> r;
    r--;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (!s[i]) {
            for (int j=min(n, i+r); j>=max(1, i-r); j--) {
                /*if (i==4) {
                    cout << "fontos " << j << " " << t[j] << "\n";
                }*/
                if (t[j]) {
                    cnt++;
                    for (int k=max(1, j-r); k<=min(n, j+r); k++) {
                        s[k]=1;
                    }
                    break;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!s[i]) {
            //cout << "baj " << i << "\n";
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << cnt << "\n";
    return 0;
}