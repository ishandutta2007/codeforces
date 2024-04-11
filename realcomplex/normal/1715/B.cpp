#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    ll low = b * k;
    ll high = b * k + n * 1ll * (k - 1);
    if(low <= s && s <= high){
        vector<ll> oo(n);
        oo[0] = b * k;
        s -= b * k;
        ll ee;
        for(int i = 0 ; i < n; i ++ ){
            ee = min(k - 1, s);
            oo[i] += ee;
            s -= ee;
        }
        for(auto x : oo)
            cout << x << " ";
        cout << "\n";
    }
    else{
        cout << "-1\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}