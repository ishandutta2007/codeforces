#include <bits/stdc++.h>

using namespace std;
long long n, dp[200005][8][8], f[8], ans, mod=998244353;; // szamjegy, ki maximalis, jo parok
string s;
void add(long long &a, long long &b) {
    a+=b;
    if (a>=mod) a-=mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    f[1]=f[6]=1, f[2]=f[5]=2, f[3]=f[4]=4;
    cin >> s;
    n=s.size();
    dp[0][7][0]=1;
    for (int i=1; i<=n; i++) {
        bool p=(s[i-1]=='1');
        for (int nagy=0; nagy<8; nagy++) {
            for (int par=0; par<8; par++) {
                long long x=dp[i-1][nagy][par];
                if (!x) continue;
                for (int kov=0; kov<8; kov++) {
                    if (p==0 && (kov & nagy)) continue;
                    int nagy2=nagy & (p==0 ? 7 : kov), par2=(par | f[kov]);
                    add(dp[i][nagy2][par2], x);
                }
            }
        }
    }
    for (int i=0; i<8; i++) {
        add(ans, dp[n][i][7]);
    }
    cout << ans << "\n";
    return 0;
}