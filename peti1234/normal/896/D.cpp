#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=30;
long long n, mod, mod2, l, r;
long long cnt, pr[k], t[k], fakt[c][k], sum=0;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            pr[++cnt]=i;
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1) {
        pr[++cnt]=n;
        result -= result / n;
    }
    return result;
}
long long oszt(long long a) {
    long long ans=1, p=mod2-1;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}

long long alatt(int a, int b) {
    if (a<b || a<0) {
        return 0;
    }
    for (int i=1; i<=cnt; i++) {
        t[i]=fakt[a][i]-fakt[b][i]-fakt[a-b][i];
    }
    long long ans=fakt[a][0]*oszt(fakt[b][0])%mod*oszt(fakt[a-b][0])%mod;
    for (int i=1; i<=cnt; i++) {
        for (int j=1; j<=t[i]; j++) {
            ans*=pr[i];
            ans%=mod;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> mod >> l >> r;
    mod2=phi(mod);
    fakt[0][0]=1;
    for (int i=1; i<=2*n; i++) {
        int s=i;
        for (int j=1; j<=cnt; j++) {
            fakt[i][j]=fakt[i-1][j];
            while (s%pr[j]==0) {
                fakt[i][j]++;
                s/=pr[j];
            }
        }
        fakt[i][0]=fakt[i-1][0]*s%mod;
    }
    for (int ossz=0; ossz<=n; ossz++) {
        int kis=(ossz+l+1)/2, nagy=(ossz+r+2)/2;
        sum+=alatt(n, ossz)*(alatt(ossz, kis)-alatt(ossz, nagy)+mod)%mod;
    }
    cout << sum%mod << "\n";
    return 0;
}