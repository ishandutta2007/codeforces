#include <bits/stdc++.h>

using namespace std;
int n, m;
int k[51][51];
long long h[51];
long long p=0;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> k[i][j];
            if (k[i][j]==1) {
                k[0][j]++;
                k[i][0]++;
            }
        }
    }
    h[0]=1;
    for (int i=1; i<=50; i++) {
        h[i]=h[i-1]*2;
    }
    for (int i=1; i<=n; i++) {
        p+=h[k[i][0]]-1;
        p+=h[m-k[i][0]]-1;
    }
    for (int i=1; i<=m; i++) {
        p+=h[k[0][i]]-1;
        p+=h[n-k[0][i]]-1;
    }
    p-=n*m;
    cout << p << endl;
    return 0;
}