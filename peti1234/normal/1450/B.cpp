#include <bits/stdc++.h>

using namespace std;
const int c=102;
int x[c], y[c], w, n, k, maxi, jo;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k, maxi=0, jo=-1;
        for (int i=1; i<=n; i++) {
            cin >> x[i] >> y[i];
        }
        for (int i=1; i<=n; i++) {
            maxi=0;
            for (int j=1; j<=n; j++) {
                maxi=max(maxi, abs(x[j]-x[i])+abs(y[j]-y[i]));
            }
            if (maxi<=k) jo=1;
        }
        cout << jo << "\n";
    }
    return 0;
}