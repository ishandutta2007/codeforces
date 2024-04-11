#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int t[c][c], x[c], y[c], ki[c], n, p;
void solve() {
    int f=n/2, edb=(f+1)/4, pdb=f/4, val=2*edb;
    for (int i=1; i<=edb; i++) x[i]=i, y[i]=val+1-i;
    for (int i=1; i<=pdb; i++) x[edb+i]=val+i, y[edb+i]=f+1-i;
    x[0]=f-pdb, y[0]=f+x[0];
    for (int i=0; i<f; i++) {
        for (int j=1; j<=f/2; j++) {
            int a=x[j]+i, b=y[j]+i;
            if (a>f) a-=f;
            if (b>f) b-=f;
            t[a][b]=i+1, t[b][a]=i+f+1;
            t[a+f][b+f]=i+1, t[b+f][a+f]=i+f+1;
        }
        int a=x[0]+i;
        if (a>f) a-=f;
        int b=a+f;
        t[a][b]=i+1, t[b][a]=i+f+1;
    }
    for (int j=1; j<f; j++) {
        for (int i=1; i<=f; i++) {
            int a=i+f+j;
            if (a>2*f) a-=f;
            t[i][a]=n+j, t[a][i]=n+f+j-1;
        }
    }
}
void dupla() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            t[i+n][j+n]=t[i][j];
        }
    }
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=n; i++) {
            int a=n+i+j;
            if (a>2*n) a-=n;
            t[i][a]=2*n-2+j, t[a][i]=3*n-2+j;
        }
    }
    n*=2;
}
int main()
{
    cin >> n;
    while(!(n%4)) n/=2, p++;
    solve();
    for (int i=1; i<=p; i++) dupla();
    for (int i=1; i<=n; i++) t[i][i]=2*n-1;
    for (int i=1; i<=n; i++) {
        ki[t[1][i]]=i-1, ki[t[i][1]]=i-1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << ki[t[i][j]] << " ";
        cout << "\n";
    }
    return 0;
}