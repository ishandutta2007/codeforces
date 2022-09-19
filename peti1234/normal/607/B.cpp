#include <bits/stdc++.h>

using namespace std;
int n;
int p[501];
int t[501][501];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
    }
    for (int i=1; i<=n; i++) {
        t[i][1]=1;
        t[i][0]=1;
    }

    for (int j=2; j<=n; j++) {
        for (int i=1; i<=n-j+1; i++) {
            int mini=INT_MAX;
            for (int k=1; k<j; k++) {
                if (t[i][k]+t[i+k][j-k]<mini) {
                    mini=t[i][k]+t[i+k][j-k];

                }
            }
            if (p[i]==p[i+j-1]) {
                if (t[i+1][j-2]<mini) {
                    mini=t[i+1][j-2];
                }
            }
            t[i][j]=mini;
        }
    }
    cout << t[1][n] << endl;
    return 0;
}