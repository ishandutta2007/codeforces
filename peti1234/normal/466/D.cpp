#include <bits/stdc++.h>

using namespace std;
long long n, h, el, ans=1, db, mod=1e9+7;
int main()
{
    cin >> n >> h, el=h;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        if (abs(x-el)>1) ans=0;
        if (x<el) db++;
        else if (x==el) ans*=(db+1), ans%=mod;
        else ans*=db, ans%=mod, db--;
        el=x;
    }
    if (db>1) ans=0;
    cout << ans << "\n";
    return 0;
}