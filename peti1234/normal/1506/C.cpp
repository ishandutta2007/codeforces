#include <bits/stdc++.h>

using namespace std;
int w, n, m, maxi;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        n=a.size(), m=b.size(), maxi=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int db=0;
                for (int k=0; ; k++) {
                    if (i+k>=n || j+k>=m || a[i+k]!=b[j+k]) {
                        break;
                    }
                    db++;
                }
                maxi=max(maxi, db);
            }
        }
        cout << n+m-2*maxi << "\n";
    }
    return 0;
}