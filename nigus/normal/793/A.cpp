#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n >> k;
    bool pos = 1;
    ll ans = 0;
    ll prev = -1;
    ll mi = big*big;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        if(c1 > 0){
            if(a%k != prev%k)pos = 0;
        }
        ans += a/k;
        mi = min(mi , a);
        prev = a;
    }

    if(pos){
        cout << ans-n*(mi/k) << "\n";
    }
    else{
        cout << -1 << "\n";
    }

    return 0;
}