#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=502, sok=1e9;
int w, n, t[c];
int dp[c][k], f[k], ki[c][k], kov[c];
bool v[k];
int holvan(int a, int b) {
    if (!ki[a][b]) {
        return a;
    }
    return ki[a][b]=holvan(ki[a][b], b);
}
int ub(int a) {
    if (a<=t[1]) {
        return 1;
    }
    if (a>t[n]) {
        return n+1;
    }
    return kov[a];

}
int solve() {
    int maxi=0;
    for (int i=0; i<k; i++) {
        v[i]=0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<k; j++) {
            ki[i][j]=0;
            dp[i][j]=-sok;
        }
        dp[i][0]=sok;
    }
    for (int i=2; i<=n; i++) {
        for (int j=t[i-1]+1; j<=t[i]; j++) {
            kov[j]=i;
        }
    }

    for (int i=n; i>=1; i--) {
        int ert=0;
        while (dp[i][ert+1]!=-sok) {
            ert++;
        }
        maxi=max(maxi, ert+1);

        for (int j=0; j<=ert+1; j++) {
            f[j]=2*t[i]-dp[i][j]+1;
            if (j) {
                f[j]=max(f[j], f[j-1]);
            }
        }
        for (int j=1; j<=ert+1; j++) {
            int kis=ub(f[j-1]), nagy=ub(f[j]);
            for (int p=holvan(kis, j); p<nagy; p=holvan(p+1, j)) {
                dp[p][j]=t[i];
                ki[p][j]=nagy;
            }
        }
    }

    return maxi;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    int ans=0;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        int ert=solve();
        ans^=ert;
    }
    cout << (ans ? "YES" : "NO") << "\n";
    return 0;
}