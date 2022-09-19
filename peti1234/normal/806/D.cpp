#include <bits/stdc++.h>

using namespace std;
const int c=2005, sok=1e9+5;
long long n, t[c][c], ans[c], mini=sok;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        ans[i]=2*sok;
    }
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            long long x;
            cin >> x;
            t[i][j]=t[j][i]=x;
            ans[i]=min(ans[i], 2*x), ans[j]=min(ans[j], 2*x);
            mini=min(mini, x);
        }
    }
    for (int i=1; i<=n; i++) {
        ans[i]-=2*mini;
    }
    for (int i=1; i<=n; i++) {
        int pos=0;
        for (int j=1; j<=n; j++) {
            if (!v[j] && (pos==0 || ans[j]<ans[pos])) {
                pos=j;
            }
        }
        v[pos]=1;
        for (int j=1; j<=n; j++) {
            if (j!=pos) {
                ans[j]=min(ans[j], ans[pos]+t[pos][j]-mini);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i]+(n-1)*mini << "\n";
    }
    return 0;
}