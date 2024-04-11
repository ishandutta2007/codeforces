#include <bits/stdc++.h>

using namespace std;
int w, n, db, t[2002];
bool v[2002];
int main()
{
    ios_base::sync_with_stdio(false), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n, db=0;
        for (int i=1; i<=2*n; i++) cin >> t[i];
        for (int i=1; i<=2*n; i++) v[i]=0;
        for (int i=1; i<=2*n; i++) for (int j=i+1; j<=2*n; j++) {
            if ((t[i]+t[j])%2==0 && !v[j]  && !v[i] && db<n-1) {
                cout << i << " " << j << "\n";
                v[i]=1, v[j]=1, db++;
                break;
            }
        }
    }
    return 0;
}