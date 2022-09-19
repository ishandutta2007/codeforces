#include <bits/stdc++.h>

using namespace std;
const int c=205;
long long n, si, dp[c][c][c][2], lep[c][2], mod=1e9+7;
string s;
int main()
{
    cin >> n >> s;
    si=s.size();
    for (int i=0; i<si; i++) {
        string p=s.substr(0, i);
        p+="(";
        for (int j=0; j<=i+1; j++) {
            if (s.substr(0, j)==p.substr(i+1-j, j)) {
                lep[i][1]=j;
            }
        }
        p[i]=')';
        for (int j=0; j<=i+1; j++) {
            if (s.substr(0, j)==p.substr(i+1-j, j)) {
                lep[i][0]=j;
            }
        }
    }
    dp[0][0][0][0]=1;
    for (int len=0; len<2*n; len++) {
        for (int a=0; a<=len; a++) {
            int b=len-a;
            for (int pref=0; pref<si; pref++) {
                for (int jo=0; jo<2; jo++) {
                    long long x=dp[len][a][pref][jo]%mod;
                    if (!x || b>a) continue;
                    for (int kov=0; kov<2; kov++) {
                        int ert=lep[pref][kov];
                        if (jo==1 || ert==si) dp[len+1][a+kov][0][1]+=x;
                        else dp[len+1][a+kov][ert][0]+=x;
                    }
                }
            }
        }
    }
    cout << dp[2*n][n][0][1]%mod << "\n";

    return 0;
}