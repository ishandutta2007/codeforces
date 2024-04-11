#include <bits/stdc++.h>

using namespace std;
int w, n, db, ert;
bool jo[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ert=1;
        int ans=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            jo[x]=1;
            while (jo[ert]) ert++;
            if (ert>i) ans++;
        }

        cout << ans << "\n";
        for (int i=1; i<=n; i++) jo[i]=0;
    }
    return 0;
}