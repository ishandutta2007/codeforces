#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

ll lcm(ll a, ll b){
    return (a * b) / __gcd(a,b);
}

ll gt(ll a, ll b, ll v){
    if(v != 0)a += (v - (a % v)) % v;
    if(v != 0)b += (v - (b % v)) % v;
    return lcm(a,b);
}

ll check(ll a, ll b){
    if(a>b)
        swap(a,b);
    ll bes = gt(a,b,0);
    ll d = b - a;
    ll cur ;
    ll ti = 0;
    for(ll x = 1; x * x <= d; x ++ ){
        if(d % x != 0) continue;
        cur = gt(a, b, x);
        if(bes > cur){
            bes = cur;
            ti = x;
        }
        else if(bes == cur){
            ti = min(ti,x);
        }
        cur = gt(a, b, d/x);
        if(bes > cur){
            bes = cur;
            ti = d/x;
        }
        else if(bes==cur){
            ti = min(ti,d/x);
        }
    }
    if(ti == 0)
        return ti;
    return (ti-(a % ti)) % ti;
}

int main(){
    fastIO;
    ll a, b;
    cin >> a >> b;
    cout << check(a, b);
    return 0;
}