#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e10

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll ava = n*n*1LL;
    ll cur;
    set<ll>hor,ver;
    ll a,b;
    for(ll j = 0;j<m;j++){
        cin >> a >> b;
        hor.insert(a);
        ver.insert(b);
        ll v = hor.size();
        ll c = ver.size();
        cur = ((v*n)+(c*n))-(c*v);
        cout << ava-cur << " ";
    }
    return 0;
}