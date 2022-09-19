#include <bits/stdc++.h>

using namespace std;
int v[5][5], n, k[1001][1001], db=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=2; i++) {
        for (int j=1; j<=4; j++) {
            v[i][j]++;
            v[j][i]+=2;
        }
    }
    for (int i=1; i<=3; i+=2) {
        for (int j=1; j<=4; j++) {
            v[i][j]+=4;
            v[j][i]+=8;
        }
    }
    n/=4;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int x=1; x<=4; x++) {
                for (int y=1; y<=4; y++) {
                    k[4*i+x][4*j+y]=v[x][y]+db;
                }
            }
            db+=16;
        }
    }
    n*=4;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << k[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}