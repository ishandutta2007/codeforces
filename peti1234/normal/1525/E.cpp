#include <bits/stdc++.h>

using namespace std;
int n, m, t[50005][22], db[22];
long long fakt=1, ans, mod=998244353;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        fakt*=i, fakt%=mod;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[j][i];
        }
    }
    for (int p=1; p<=m; p++) {
        for (int i=1; i<=n; i++) {
            db[i]=i;
        }
        for (int i=1; i<=n; i++) {
            int s=t[p][i];
            for (int j=s; j<=n; j++) {
                db[j]--;
            }
        }
        long long pr=1;
        for (int i=1; i<=n; i++) {
            pr*=db[i];
            pr%=mod;
        }
        ans+=mod+fakt-pr;
        ans%=mod;
    }
    //cout << "vege " << ans << "\n";
    cout << ans*oszt(fakt)%mod << "\n";
    return 0;
}