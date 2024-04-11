#include <bits/stdc++.h>

using namespace std;
int w, n, m, db, t[305];

int main()
{
    cin >> w;
    while (w--) {
        cin >> m >> n;
        for (int i=1; i<=n; i++)  {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (t[i]<t[j]) {
                    db++;
                }
            }
        }
        cout << db << "\n";
        db=0;
    }
    return 0;
}