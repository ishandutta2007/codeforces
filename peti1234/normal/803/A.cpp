#include <bits/stdc++.h>

using namespace std;
int n, k;
int t[101][101];
int main()
{
    cin >> n >> k;
    if (k>n*n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            if (k>=1+(i!=j)) {
                t[i][j]=1;
                t[j][i]=1;
                k-=(1+(i!=j));
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}