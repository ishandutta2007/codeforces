#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int w, n, t[c], db[c][c];
long long sum;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                db[i][j]=db[i][j-1]+(t[i]>t[j]);
            }
            for (int j=n; j>=i; j--) {
                db[i][j]=db[i][j+1]+(t[i]>t[j]);
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                sum+=db[i][j+1]*db[j][i-1];
            }
        }
        cout << sum << "\n";
        sum=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                db[i][j]=0;
            }
        }
    }
    return 0;
}