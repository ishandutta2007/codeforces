#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long n, dp[c][8][3], fakt[c][3], inv[c][3], cnt[c], mod[3];
int mini=c;
long long oszt(long long a, long long b) {
    long long ans=1, p=b-2;
    while(p) {
        if (p%2) {
            ans*=a, ans%=b;
        }
        a*=a, a%=b;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b, long long j) {
    if (a<b) {
        return 0;
    }
    return fakt[a][j]*inv[b][j]%mod[j]*inv[a-b][j]%mod[j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    mod[0]=998244353, mod[1]=1000000007, mod[2]=1000000009;
    cin >> n;
    for (int j=0; j<3; j++) {
        fakt[0][j]=1, inv[0][j]=1;
        for (int i=1; i<c; i++) {
            fakt[i][j]=fakt[i-1][j]*i%mod[j];
            inv[i][j]=oszt(fakt[i][j], mod[j]);
        }
    }
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i=1; i<c; i++) {
        for (int j=2*i; j<c; j+=i) {
            cnt[i]+=cnt[j];
        }
    }
    for (int j=0; j<3; j++) {
        for (int i=c-1; i>=1; i--) {
            for (int k=1; k<=7; k++) {
                long long ert=alatt(cnt[i], k, j);
                for (int ii=2*i; ii<c; ii+=i) {
                    ert-=dp[ii][k][j];
                    if (ert<0) {
                        ert+=mod[j];
                    }
                }
                dp[i][k][j]=ert;
                if (i==1 && ert) {
                    mini=min(mini, k);
                }
            }
        }
    }
    cout << (mini==c ? -1 : mini) << "\n";
    return 0;
}