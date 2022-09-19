#include <bits/stdc++.h>

using namespace std;
long long n, k, sum=1, ans, mod=998244353;
bool p=false;
long long db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x>=n-k+1) {
            p=true;
            ans+=x;
            sum*=(db+1);
            sum%=mod;
            db=0;
        } else {
            if (p) db++;
        }
    }
    cout << ans << " " << sum << endl;
    return 0;
}