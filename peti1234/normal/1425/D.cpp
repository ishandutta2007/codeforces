#include <bits/stdc++.h>

using namespace std;
const int c=2002, mod=1e9+7;
long long sum, fakt[c], inv[c];
int n, m, k, x[c], y[c], d[c], db[c], kom[c][c];
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        p/=2, a*=a, a%=mod;
    }
    return ans;
}
long long t(int a, int b) {
    int x1=max(0, max(x[a], x[b])-k-1), x2=min(c-1, min(x[a], x[b])+k);
    int y1=max(0, max(y[a], y[b])-k-1), y2=min(c-1, min(y[a], y[b])+k);
    if (x1>x2 || y1>y2) return 0;
    return kom[x2][y2]-kom[x1][y2]-kom[x2][y1]+kom[x1][y1];
}
long long alatt(long long a, long long b) {
    if (a<b) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i] >> d[i];
        kom[x[i]][y[i]]=1;
    }
    for (int i=1; i<c; i++) {
        for (int j=1; j<c; j++) {
            kom[i][j]+=kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        db[i]=t(i, i);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int koz=t(i, j), u=n-db[i]-db[j]+koz;
            sum+=(alatt(n, m)+alatt(u, m)-alatt(n-db[i], m)-alatt(n-db[j], m)+2*mod)%mod*d[i]%mod*d[j];
            sum%=mod;
        }
    }
    cout << sum << "\n";
    return 0;
}