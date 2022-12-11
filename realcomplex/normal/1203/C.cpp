#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
    fastIO;
    int n;
    cin >> n;
    ll a;
    cin >> a;
    ll x;
    for(int i = 1; i < n; i ++ ){
        cin >> x;
        a = __gcd(a,x);
    }
    int res = 0;
    for(ll t = 1; t * t <= a; t ++ ){
        if(a % t == 0){
            res ++ ;
            res += (t * t) != a;
        }
    }
    cout << res << "\n";
    return 0;
}