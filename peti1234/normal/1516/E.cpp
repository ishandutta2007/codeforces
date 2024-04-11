#include <bits/stdc++.h>

using namespace std;
const int c=205;
long long n, k, ert, dp[c][c][c], gyors[c][c][2*c], sum[c], fakt[2*c], ut[2*c], mod=1e9+7;
bool v[c][c][2*c];
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long oszt(long long a) {
    return po(a, mod-2);
}
long long alatt(long long a, long long b) {
    if (a<0 || a<b) {
        return 0;
    }
    return ut[n-a+b]*oszt(ut[n-a])%mod*oszt(fakt[b])%mod;
}
int main()
{
    cin >> n >> k;

    ert=min(n, k);
    fakt[0]=1, ut[0]=1;
    for (int i=1; i<=2*ert; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        ut[i]=ut[i-1]*(n-i+1)%mod;
    }
    dp[1][0][0]=1;
    for (int kor=2; kor<=ert+1; kor++) {
        for (int kordb=0; kordb*(kor-1)<=ert; kordb++) {
            if (kor*kordb>n) {
                continue;
            }
            long long add=kordb*(kor-1);
            for (int i=0; i+add<=ert; i++) {
                for (int j=0; j<=i; j++) {
                    if (!v[kor][kordb][i+j]) {
                        gyors[kor][kordb][i+j]=alatt(n-i-j, kor*kordb)*fakt[kor*kordb]%mod*oszt(po(kor, kordb))%mod*oszt(fakt[kordb])%mod;
                        v[kor][kordb][i+j]=1;
                    }
                    long long mul=gyors[kor][kordb][i+j];
                    //cout << kor << " " << kordb << " " << i+j << " " << mul << "\n";
                    dp[kor][i+add][j+kordb]+=dp[kor-1][i][j]*mul;
                    dp[kor][i+add][j+kordb]%=mod;
                }
            }
        }
    }
    for (int i=0; i<=ert; i++) {
        for (int j=0; j<=i; j++) {
            sum[i]+=dp[ert+1][i][j];
            sum[i]%=mod;
        }
    }
    for (int i=1; i<=k; i++) {
        if (i>=2) {
            sum[i]+=sum[i-2];
            sum[i]%=mod;
        }
        cout << sum[i] << " ";
    }
    return 0;
}
/*
1000000000 200
*/