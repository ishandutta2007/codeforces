
#include <bits/stdc++.h>

using namespace std;
const int c=128;
int t[c], dp[c][8], n, k, h[8], p[2002], ert, db[c];
bool v[2002][2012];
bool jo(int a, int b) {
    while(a>0) {
        if (a%2 && b%2) return 0;
        a/=2, b/=2;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<c; i++) t[i]=-1;
    t[119]=0, t[36]=1, t[93]=2, t[109]=3, t[46]=4, t[107]=5, t[123]=6, t[37]=7, t[127]=8, t[111]=9;
    h[0]=1;
    for (int i=1; i<8; i++) h[i]=2*h[i-1];
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s, ert=0;
        for (int i=0; i<8; i++) if (s[i]=='1') ert+=h[i];
        p[i]=ert;
    }
    for (int i=0; i<c; i++) {
        int x=i, y=0;
        while(x) y+=x%2, x/=2;
        db[i]=y;
    }
    for (int i=0; i<c; i++) {
        for (int j=0; j<8; j++) dp[i][j]=-1;
        for (int j=0; j<c; j++) if (jo(i, j)) {
            dp[i][db[j]]=max(dp[i][db[j]], t[i+j]);
        }
    }

    v[n+1][0]=1;
    for (int i=n; i>=1; i--) for (int j=k; j>=0; j--) for (int l=0; l<8; l++) if (v[i+1][j] && dp[p[i]][l]!=-1) v[i][j+l]=1;
    if (!v[1][k]) cout << -1 << "\n";
    else {
        for (int i=1; i<=n; i++) {
            int maxi=-1, x=-1, a=p[i];
            for (int j=0; j<8; j++) if (dp[a][j]>maxi && v[i+1][k-j]) maxi=dp[a][j], x=j;
            cout << maxi, k-=x;
        }
    }
    return 0;
}