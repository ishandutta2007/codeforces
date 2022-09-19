#include <bits/stdc++.h>

using namespace std;
int w, n, t[52], db;
bool v[52];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, db=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=50; i++) {
            v[i]=0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                int ert=t[j]-t[i];
                if (!v[ert]) {
                    db++;
                    v[ert]=1;
                }
            }
        }
        cout << db << "\n";
    }
    return 0;
}