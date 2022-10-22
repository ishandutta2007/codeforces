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

    cin >> n >> m >> k;
    vector<ll> A;
    ll ans = big*big;
    for(ll c1 = 0; c1<  n; c1++){
        ll a;
        cin >> a;
        A.push_back(a);
        if(a != 0 && a <= k){
            ans = min(ans , 10*abs(c1+1-m));
        }
    }
    cout << ans << "\n";
    return 0;
}