#include <bits/stdc++.h>

using namespace std;
const int c=17, c2=1<<17, N=1005;
int n, t[N], cnt;
long long dp[c2][c+1], po[c+1][N], mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=c; i++) {
        po[i][0]=1;
        for (int j=1; j<=n; j++) {
            po[i][j]=po[i][j-1]*i%mod;
        }
    }
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        if (c=='?') t[i]=-1, cnt++;
        else t[i]=(c-'a');
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=i+1; j++) {
            int bal=i, jobb=j, ert=cnt, mask=0, f=0;
            while (1<=bal && jobb<=n) {
                if (bal!=jobb) {
                    if (t[bal]!=-1 && t[jobb]!=-1) {
                        if (t[bal]!=t[jobb]) f=1;
                    }
                    else {
                        ert--;
                        if (t[bal]!=-1) mask=mask|(1<<t[bal]);
                        if (t[jobb]!=-1) mask=mask|(1<<t[jobb]);
                    }
                }
                if (!f) {
                    for (int db=1; db<=c; db++) {
                        dp[mask][db]+=po[db][ert];
                    }
                }
                bal--, jobb++;
            }
        }
    }
    for (int lep=0; lep<c; lep++) {
        for (int mask=0; mask<c2; mask++) {
            for (int pc=1; pc<=c; pc++) {
                int s=(1<<lep);
                if ((mask & s)==0) {
                    int kov=mask+s;
                    dp[kov][pc]=(dp[kov][pc]+dp[mask][pc])%mod;
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int mask=0;
        string s;
        cin >> s;
        for (auto p:s) {
            mask+=(1<<(p-'a'));
        }
        int pc=__builtin_popcount(mask);
        cout << dp[mask][pc] << "\n";
    }
    return 0;
}
/*
7
ab??aba
1
a
*/