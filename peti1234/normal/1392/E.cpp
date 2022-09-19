#include <bits/stdc++.h>

using namespace std;
long long t[27][27], n, q, po=1, p;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) t[i][n+1]=1;
    for (int j=2; j<=n; j+=2) t[n+1][j]=1;
    for (int j=2; j<=n; j+=2) {
        for (long long i=1; i<=n; i++) t[i][j]=po*(1<<(i-1));
        po*=4;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << t[i][j] << " ";
        cout.flush() << "\n";
    };
    cin >> q;
    while(q--) {
        cin >> p;
        int x=1, y=1;
        cout << x << " " << y << "\n";
        while(x+y<2*n) {
            if (p%2==(t[x+1][y]!=0)) x++;
            else y++;
            p/=2;
            cout.flush() << x << " " << y << "\n";
        }
    }
    return 0;
}