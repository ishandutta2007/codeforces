#include <bits/stdc++.h>

using namespace std;
long long n, po[60], t[8][8], pc[128], ert[128], inv[8][128], s[8], mod=1e9+7, inv100=(mod*57+1)/100;
map<long long, long long> m[8];
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1;
    for (int i=1; i<60; i++) po[i]=po[i-1]*2;
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=0; j<n; j++) {
        cin >> t[i][j];
        t[i][j]=t[i][j]*inv100%mod;
    }
    for (int i=0; i<(1<<n); i++) {
        pc[i]=__builtin_popcount(i);
        ert[i]=s[pc[i]]++;
        inv[pc[i]][ert[i]]=i;
    }
    m[0][1]=1;
    for (int i=1; i<=n; i++) {
        for (int mask=0; mask<(1<<n); mask++) {
            long long prob=1;
            for (int j=0; j<n; j++) {
                prob*=(mask & (1<<j) ? t[i][j] : mod+1-t[i][j]);
                prob%=mod;
            }
            for (auto el:m[i-1]) {
                long long mask2=el.first, pr=el.second, res=0;
                for (int j=0; j<40; j++) {
                    if (mask2 & po[j]) {
                        int kezd=inv[i-1][j];
                        for (int cel=0; cel<n; cel++) {
                            if ((mask & po[cel]) && (kezd & po[cel])==0) {
                                res|=po[ert[kezd+(1<<cel)]];
                            }
                        }
                    }
                }
                m[i][res]=(m[i][res]+prob*pr)%mod;
            }
        }
    }
    cout << m[n][1] << "\n";
    return 0;
}