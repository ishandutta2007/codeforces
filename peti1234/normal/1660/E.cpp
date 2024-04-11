#include <bits/stdc++.h>

using namespace std;
int w, n, sum, db[2005], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char c;
                cin >> c;
                if (c=='1') {
                    sum++;
                    db[(i+n-j)%n]++;
                }
            }
        }
        for (int i=0; i<n; i++) {
            maxi=max(maxi, db[i]);
        }
        cout << sum+n-2*maxi << "\n";

        maxi=0, sum=0;
        for (int i=0; i<n; i++) {
            db[i]=0;
        }
    }
    return 0;
}