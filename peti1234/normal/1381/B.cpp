#include <bits/stdc++.h>

using namespace std;
const int c=4002;
bool v[c];
int w, n, maxi, db;
int main()
{
    cin >> w, v[0]=1;
    while(w--) {
        cin >> n, maxi=0, db=0;
        for (int i=1; i<=n; i++) v[i]=0;
        for (int i=1; i<=2*n; i++) {
            int x; cin >> x;
            if (x>maxi) {
                for (int i=n; i>=0; i--) if (v[i]) v[i+db]=1;
                maxi=x, db=0;
            }
            db++;
        }
        for (int i=n; i>=0; i--) if (v[i]) v[i+db]=1;
        if (v[n]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}