#include <bits/stdc++.h>

using namespace std;
const int c=12;
long long dp[1<<c][c][c][c], dp2[2*c][c][c][c], mod=998244353; // (mask, ut, inv, szomszedosok), (hossz, db, inv, szomszedok)
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<0) return 0;
    long long ans=1;
    for (int i=1; i<=b; i++) {
        ans=ans*oszt(i)%mod*(a+1-i)%mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    dp[0][0][0][0]=1, dp2[0][0][0][0]=1;
    for (int mask=0; mask<(1<<c); mask++) {
        for (int ut=0; ut<c; ut++) {
            for (int inv=0; inv<c; inv++) {
                for (int szom=0; szom<c; szom++) {
                    int ert=dp[mask][ut][inv][szom], pc=__builtin_popcount(mask);
                    if (!ert) continue;
                    if (pc && __builtin_popcount(mask+1)==1) {
                        if (pc>1) {
                            dp2[pc][1][inv][szom]+=ert;
                        }
                        continue;
                    }
                    for (int kov=0; kov<c; kov++) {
                        if (mask & (1<<kov)) continue;
                        int add=0, pl=(kov<ut);
                        for (int j=kov+1; j<c; j++) {
                            if (mask & (1<<j)) {
                                add++;
                            }
                        }
                        if (inv+add<c && szom+pl<c) {
                            if (inv+add==3 && szom+pl==1 && mask+(1<<kov)==15) {
                                //cout << "cel " << mask << " " << ut << " " << kov << " " << ert << "\n";
                            }
                            dp[mask+(1<<kov)][kov][inv+add][szom+pl]+=ert;
                        }
                    }
                }
            }
        }
    }
    //cout << "alap " << dp2[4][1][3][1] << "\n";
    for (int hossz=1; hossz<2*c; hossz++) {
        for (int db=0; db<c; db++) {
            for (int inv=0; inv<c; inv++) {
                for (int szom=0; szom<c; szom++) {
                    int ert=dp2[hossz][db][inv][szom];
                    if (!ert) continue;
                    for (int h2=0; h2<2*c-hossz; h2++) {
                        for (int inv2=0; inv+inv2<c; inv2++) {
                            for (int szom2=0; szom+szom2<c; szom2++) {
                                long long ert2=dp2[h2][1][inv2][szom2];
                                dp2[hossz+h2][db+1][inv+inv2][szom+szom2]+=ert*ert2;
                            }
                        }
                    }
                }
            }
        }
    }

    int w;
    cin >> w;
    while (w--) {
        long long n, inv, szom, ans=0;
        cin >> n >> inv >> szom;
        for (int hossz=1; hossz<2*c; hossz++) {
            for (int db=0; db<c; db++) {
                long long ert=(dp2[hossz][db][inv][szom]);
                if (!ert) continue;
                //cout << "fontos " << ert << " " << hossz << " " << db << "\n";
                ans=(ans+ert*alatt(n-hossz+db, db))%mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
4 1 2 3
2 3 4 1
2 4 1 3
*/