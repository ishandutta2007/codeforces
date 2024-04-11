#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool get(ll x){
    cout << "? " << x << endl;
    ll sol;
    cin >> sol;
    if(sol) return true;
    return false;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> ord;
    ll li = 0, ri = n;
    ll mid;
    while(li + 1 < ri){
        mid = (li + ri) / 2ll;
        ord.push_back(mid);
        li=mid;
    }
    ll cur = 1;
    ll sign = +1;
    for(int y = ord.size() - 1; y >= 0 ; y -- ){
        cur += sign * ord[y];
        sign = -sign;
    }
    get(cur);
    li = 0, ri = n;
    while(li + 1 < ri){
        mid = (li + ri) / 2ll;
        cur += sign * mid;
        sign = -sign;
        if(get(cur))
            ri = mid;
        else
            li = mid;
    }
    cout << "= " << ri << endl;
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}