#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[51][8];
int h[51][4];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        h[i][1]=100;
        h[i][2]=100;
        h[i][3]=100;
    }
    for (int i=1; i<=n; i++) {
        string x;
        cin >> x;
        for (int j=0; j<m; j++) {
            if (x[j]>='0' && x[j]<='9') {
                h[i][1]=min(h[i][1], min(j, m-j));
            }
            if (x[j]>='a' && x[j]<='z') {
                h[i][2]=min(h[i][2], min(j, m-j));
            }
            if (x[j]=='#' or x[j]=='&' or x[j]=='*') {
                h[i][3]=min(h[i][3], min(j, m-j));
            }
        }
    }
    /*for (int i=1; i<=n; i++) {
        for (int j=1; j<=3; j++) {
            cout << h[i][j] << " ";
        }
        cout << endl;
    }*/
    for (int i=0; i<=n; i++) {
        for (int j=1; j<=7; j++) {
            t[i][j]=100;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int k=1; k<=3; k++) {
            for (int j=1; j<=7; j++) {
                t[i][j]=min({t[i][j], t[i-1][j], t[i-1][j&~(1<<k-1)]+h[i][k]}); // 1 eltolsa valami s 1=1
            }
        }
    }
    cout << t[n][7] << endl;
    return 0;
}