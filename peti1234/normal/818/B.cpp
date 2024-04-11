#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, m, t[c], ans[c], fix[c];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> t[i];
    }
    for (int i=1; i<m; i++) {
        int dif=t[i+1]-t[i]+n;
        if (dif>n) dif-=n;
        int pos=t[i];
        if (ans[pos] && ans[pos]!=dif) {
            cout << -1 << "\n";
            return 0;
        }
        ans[pos]=dif;
        fix[dif]=1;
    }
    for (int i=1; i<=n; i++) {
        if (!ans[i]) {
            for (int j=1; j<=n; j++) {
                if (!fix[j]) {
                    ans[i]=j;
                    fix[j]=1;
                    break;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (ans[i]==ans[j]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
6 8
2 5 4 2 5 4 2 5
*/