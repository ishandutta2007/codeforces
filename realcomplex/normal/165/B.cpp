#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e5

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

ll w(ll n,ll k){
    ll p = k;
    ll a = n;
    while(p<=n){
        a += n/p;
        p*=k;
    }
    return a;
}

main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll l = -1,r = 100000000005;
    ll m;
    while(r-l>1){
        m = (l+r)/2;
        ll tek = w(m,k);
        if(tek>=n){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << r;
    return 0;
}