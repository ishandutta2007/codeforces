#include <bits/stdc++.h>

using namespace std;
int w, n, bal, jobb, maxi, t[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]==1) {
                bal=i, jobb=i, maxi=1;
            }
        }
        t[0]=n+1, t[n+1]=n+1;
        for (int i=1; i<=n; i++) {
            cout << (maxi==i);
            if (t[bal-1]<t[jobb+1]) {
                bal--;
                maxi=max(maxi, t[bal]);
            } else {
                jobb++;
                maxi=max(maxi, t[jobb]);
            }
        }
        cout << "\n";
    }
    return 0;
}