#include <bits/stdc++.h>

using namespace std;
const int c=55;
int kis[c], nagy[c], par[5005], ans, n, q;
int cnt, ert=1;
bool v[5005];
bool dfs(int a) {
    v[a]=true;
    for (int i=kis[a]; i<=nagy[a]; i++) {
        for (int pl=1; pl<=ert; pl++) {
            int cs=i+pl*n;
            if (!v[cs]) {
                v[cs]=1;
                if (!par[cs] || dfs(par[cs])) {
                    par[a]=cs, par[cs]=a;
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        kis[i]=1, nagy[i]=n;
    }
    for (int i=1; i<=q; i++) {
        int t, l, r, ert;
        cin >> t >> l >> r >> ert;
        for (int i=l; i<=r; i++) {
            if (t==1) {
                kis[i]=max(kis[i], ert);
            }
            if (t==2) {
                nagy[i]=min(nagy[i], ert);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (kis[i]>nagy[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    ans=n;
    for ( ; ert<=n; ert++) {
        cnt=0;
        for (int cs=1; cs<=n; cs++) {
            for (int i=1; i<=(ert+1)*n; i++) {
                v[i]=0;
            }
            cnt+=dfs(cs);
        }
        ans+=2*(n-cnt);
        for (int i=1; i<=(ert+1)*n; i++) {
            par[i]=0;
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
3 2
1 1 3 2
2 1 3 2
*/