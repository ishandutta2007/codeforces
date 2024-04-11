#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, m, k;
        cin >> n >> m >> k;
        int pos=0, ert1=(n+m-1)/m, db1=n%m, ert2=n/m, db2=m-db1;
        for (int i=1; i<=k; i++) {
            for (int j=1; j<=db1; j++) {
                cout << ert1 << " ";
                for (int s=1; s<=ert1; s++) {
                    pos++;
                    if (pos>n) pos=1;
                    cout << pos << " ";
                }
                cout << "\n";
            }
            for (int j=1; j<=db2; j++) {
                cout << ert2 << " ";
                for (int s=1; s<=ert2; s++) {
                    pos++;
                    if (pos>n) pos=1;
                    cout << pos << " ";
                }
                cout << "\n";
            }
            pos=(pos+db1*ert1)%n;
        }
    }
    return 0;
}