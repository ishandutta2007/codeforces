#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,r,req;
    cin >> n >> r >> req;
    ll val = req*n;
    ll tek = 0;
    ll ans = 0;
    pair<ll,ll>ex[n];
    for(ll j = 0;j<n;j++){
        cin >> ex[j].se >> ex[j].fi;
        tek += ex[j].se;
    }
    sort(ex,ex+n);
    ll grade,exams;
    for(ll x = 0;x<n&&tek<val;x++){
        grade = ex[x].se;
        exams = ex[x].fi;
        ans += min(r-grade,val-tek)*exams;
        tek += min(r-grade,val-tek);
    }
    cout << ans;
    return 0;
}