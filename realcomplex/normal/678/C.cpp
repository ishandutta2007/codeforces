#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mkd(ll a,ll b){
        return a*(b/__gcd(a,b));
}

int main(){
        ll n,a,b,p,q;
        cin >> n >> a >> b >> p >> q;
        ll vi = mkd(a,b);
        ll both = n/vi;
        ll ans = (n/a-both)*p;
        ans += (n/b-both)*q;
        ans += both*max(p,q);
        cout << ans << "\n";
        return 0;
}