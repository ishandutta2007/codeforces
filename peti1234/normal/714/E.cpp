#include <bits/stdc++.h>

using namespace std;
const long long c=3002;
priority_queue<long long> kis, nagy;
long long sum[c][c], mid[c][c], dp[c], ert[c], t[c];
long long n, ksum, nsum, ksi, nsi, ke, ne;
void kpb(long long a) {
    kis.push(a), ksi++, ksum+=a;
}
void npb(long long a) {
    nagy.push(a), nsi++, nsum-=a;
}
void kkv(long long a) {
    kis.pop(), ksi--, ksum-=a;
}
void nkv(long long a) {
    nagy.pop(), nsi--, nsum-=a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> t[i], t[i]-=i;
    for (long long i=1; i<=n; i++) {
        while(kis.size()) kis.pop();
        while(nagy.size()) nagy.pop();
        ksum=0, nsum=0, ksi=0, nsi=0;
        for (long long j=i; j<=n; j++) {
            ksi=kis.size(), nsi=nagy.size();
            if (kis.empty() || t[j]<=kis.top()) kpb(t[j]);
            else npb(-t[j]);
            while(nsi>ksi) kpb(-nagy.top()), nkv(-nagy.top());
            while(ksi-2>nsi) npb(-kis.top()), kkv(kis.top());
            long long x=kis.top(); mid[i][j]=x, sum[i][j]=x*ksi-ksum+nsum-x*nsi;
        }
    }
    for (long long i=1; i<=n; i++) {
        dp[i]=sum[1][i], ert[i]=mid[1][i];
        for (long long j=1; j<i; j++) {
            long long x=dp[j]+sum[j+1][i], y=ert[j], z=mid[j+1][i];
            if (x<dp[i] && y<=z) dp[i]=x, ert[i]=z;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}