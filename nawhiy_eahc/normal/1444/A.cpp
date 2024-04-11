#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll compute(ll p, ll q, ll i){
    if(i == 1) return 1;
    while(p%q == 0){
        p /= i;
    }

    return p;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll p, q; cin >> p >> q;
        if(p%q){
            cout << p << "\n";
            continue;
        }

        ll ans = 1;

        for(ll i = 1;i*i <= q; i++){
            if(q%i == 0){
                ans = max(ans, compute(p, q, i));
                ans = max(ans, compute(p, q, q/i));
            }
        }

        cout << ans << "\n";
    }
}