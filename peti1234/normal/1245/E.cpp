#include <bits/stdc++.h>

using namespace std;
const int c=11;
int n=10, t[c][c], kov[c*c];
long double prob[c*c];
int main()
{
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            t[i][j]=(i%2 ? n*(i-1)+j : n*i+1-j);
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            kov[t[i][j]]=t[i+x][j];
        }
    }
    for (int i=n*n-6; i<n*n; i++) {
        prob[i]=6.0;
    }
    for (int i=n*n-7; i>=1; i--) {
        for (int j=i+1; j<=i+6; j++) {
            prob[i]+=min(prob[j], prob[kov[j]]);
        }
        prob[i]=prob[i]/6+1;
    }
    cout.precision(20);
    cout << prob[1] << "\n";
    return 0;
}