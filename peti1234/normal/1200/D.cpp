#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int n, k, skezd[c], sveg[c], okezd[c], oveg[c], t[c][c], ans, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c=='B') {
                if (!skezd[i]) skezd[i]=j;
                sveg[i]=j;
                if (!okezd[j]) okezd[j]=i;
                oveg[j]=i;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        int a=skezd[i], b=sveg[i], ert=max(1, i-k+1);
        if (!a) ans++;
        else {
            if (b-a<k) {
                int b2=max(1, b-k+1);
                //cout << "sor " << i << " " << a << " " << b << "\n";
                t[ert][b2]++;
                t[i+1][b2]--;
                t[ert][a+1]--;
                t[i+1][a+1]++;
            }
        }
        a=okezd[i], b=oveg[i];
        if (!a) ans++;
        else {
            if (b-a<k) {
                int b2=max(1, b-k+1);
                //cout << "oszlop " << i << " " << a << " " << b << "\n";
                t[b2][ert]++;
                t[b2][i+1]--;
                t[a+1][ert]--;
                t[a+1][i+1]++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            t[i][j]=t[i][j]+t[i-1][j]+t[i][j-1]-t[i-1][j-1];
            maxi=max(maxi, t[i][j]);
        }
    }
    cout << ans+maxi << "\n";
    return 0;
}