#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll cum(ll x){
    ll rr = 0;
    while(x > 0){
        rr += x % 10;
        x /= 10;
    }
    return rr;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        ll n;
        cin >> n;
        while(__gcd(n, cum(n)) == 1) n ++ ; // < 9
        cout << n << "\n";
    }
    return 0;
}