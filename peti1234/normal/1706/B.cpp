#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, db[c], ut[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (ut[x]==0 || (i-ut[x])%2) {
                db[x]++, ut[x]=i;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << db[i] << " ";
            db[i]=0, ut[i]=0;
        }
        cout << "\n";
    }
    return 0;
}