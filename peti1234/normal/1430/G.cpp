#include <bits/stdc++.h>
using namespace std;
const int c=(1<<18), p=200, sok=1e9;
int n, m, a[p], b[p], r[p], w[p], s[c], dp[c], ki[c], f[c];
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> a[i] >> b[i] >> w[i];
    for (int i=0; i<c; i++) {
        for (int j=0; j<m; j++) {
            int x=i&(1<<(a[j]-1)), y=i&(1<<(b[j]-1));
            if (x&&y) f[i]=1;
            if (!x&&y) s[i]+=w[j];
            if (x&&!y) s[i]=sok;
        }
    }
    for (int i=1; i<c; i++) {
        dp[i]=sok;
        if (s[i]<sok) {
            for (int j=i; j; j=(j-1)&i) {
                if (!f[j] && dp[i-j]<dp[i]) {
                    dp[i]=dp[i-j], ki[i]=j;
                }
            }
            dp[i]+=s[i];
        }
    }
    for (int i=c-1; i; i-=ki[i]) {
        for (int j=0; j<n; j++) {
            if (!(i&(1<<j))) r[j]++;
        }
    }
    for (int i=0; i<n; i++) cout << r[i] << " ";
    return 0;
}