#include <bits/stdc++.h>

using namespace std;
const long long c=512, mod=998244353;
long long regi[c], uj[c], n, m, es[10], vagy[10];
bool el[10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i=0; i<m; i++) {
        long long x, y;
        cin >> x >> y;
        el[y][x]=1;
    }
    for (long long i=0; i<10; i++) {
        for (long long j=0; j<i; j++) {
            es[i]|=(1<<j);
        }
    }
    for (long long y=0; y<10; y++) {
        for (long long x=0; x<y; x++) {
            if (el[y][x]) continue;
            long long s=(1<<x);
            vagy[y]|=s;
            vagy[x]|=(1<<y);
            if (es[y] & s) {
                es[y]-=s;
            }
        }
    }
    for (long long i=0; i<10; i++) {
        es[i]=c-1-es[i];
    }

    regi[c-1]=1;
    for (long long j=1; j<=n; j++) {
        for (long long mask=0; mask<c; mask++) {
            if (regi[mask]==0) continue;
            for (long long i=0; i<10; i++) {
                if (i==9 || (mask & (1<<i))) {
                    long long kov=(mask|vagy[i])&es[i];
                    uj[kov]+=regi[mask];
                    if (uj[kov]>=mod) uj[kov]-=mod;
                }
            }
        }
        for (long long mask=0; mask<c; mask++) {
            regi[mask]=uj[mask];
            uj[mask]=0;
        }
    }
    long long sum=0;
    for (long long mask=0; mask<c; mask++) {
        sum=(sum+regi[mask])%mod;
    }
    cout << sum << "\n";
    return 0;
}