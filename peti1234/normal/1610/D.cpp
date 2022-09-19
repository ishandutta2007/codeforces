#include <bits/stdc++.h>

using namespace std;
int n, db[35];
long long ans, mod=1e9+7;
long long po(int db) {
    long long ans=1;
    while (db--) ans=2*ans%mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[__builtin_ctz(x)]++;
    }
    ans=po(n)-1;
    for (int i=30; i>=1; i--) {
        db[i]+=db[i+1];
        if (db[i]>db[i+1]) ans=(ans+mod-po(db[i]-1))%mod;
    }
    cout << ans << "\n";
    return 0;
}