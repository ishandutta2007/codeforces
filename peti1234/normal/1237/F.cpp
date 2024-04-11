#include <bits/stdc++.h>

using namespace std;
const int c=3602, mod=998244353;
int n, m, k, si, sdb, odb, us, uo;
long long sum, fakt[c], inv[c], sdp[c][c], odp[c][c];
bool s[c], o[c];
vector<int> sor, oszlop;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(int a, int b) {
    if (a<b) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    cin >> n >> m >> k;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=max(n, m); i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=1; i<=2*k; i++) {
        int x, y; cin >> x >> y;
        s[x]=1, o[y]=1;
    }
    sdp[0][0]=1;
    sor.push_back(0), si=1;
    for (int i=1; i<=n; i++) {
        if (!s[i]) {
            sdb++;
            int el=sor.back();
            for (int j=0; j<=n; j++) {
                sdp[i][j]=sdp[el][j];
            }
            if (i==el+1 && si!=1) {
                int ke=sor[si-2];
                for (int j=1; j<=n; j++) {
                    sdp[i][j]+=sdp[ke][j-1];
                    sdp[i][j]%=mod;
                }
            }
            sor.push_back(i);
            si++;
        }
    }
    us=sor.back();
    odp[0][0]=1;
    oszlop.push_back(0), si=1;
    for (int i=1; i<=m; i++) {
        if (!o[i]) {
            odb++;
            int el=oszlop.back();
            for (int j=0; j<=m; j++) {
                odp[i][j]=odp[el][j];
            }
            if (i==el+1 && si!=1) {
                int ke=oszlop[si-2];
                for (int j=1; j<=m; j++) {
                    odp[i][j]+=odp[ke][j-1];
                    odp[i][j]%=mod;
                }
            }
            oszlop.push_back(i);
            si++;
        }
    }
    uo=oszlop.back();
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (2*i+j<=sdb && 2*j+i<=odb) {
                sum+=sdp[us][i]*odp[uo][j]%mod*alatt(sdb-2*i, j)%mod*alatt(odb-2*j, i)%mod*fakt[i]%mod*fakt[j]%mod;
                sum%=mod;
            }
        }
    }
    cout << sum << "\n";
    return 0;
}