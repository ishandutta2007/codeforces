#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, t[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=n; i>=1; i--) {
            if (i+t[i]<=n) {
                t[i]+=t[i+t[i]];
            }
            maxi=max(maxi, t[i]);
        }
        cout << maxi << "\n";
    }
    return 0;
}