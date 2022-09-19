#include <bits/stdc++.h>

using namespace std;
const int c=502;
int n, t[c][c];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i][i];
    }
    for (int dif=1; dif<n; dif++) {
        bool spec=0;
        for (int i=dif+1; i<=n; i++) {
            int j=i-dif;
            if (t[i-1][j]==dif) {
                spec=1;
            }
            if (spec) {
                t[i][j]=t[i][j+1];
            } else {
                t[i][j]=t[i-1][j];
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}