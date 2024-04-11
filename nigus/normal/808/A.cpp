#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef  long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T;
vector<ll> luck;

ll solve(ll i){
    for(ll c1 = 1; c1 < 10; c1++){
        ll a = c1;
        while(a <= 3000000000){
            luck.push_back(a);
            a *= 10;
        }
    }
    sort(all(luck));
    for(ll c1 = 0; c1 < luck.size(); c1++){
        if(i < luck[c1])return luck[c1]-i;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;
    cin >> a;
    cout << solve(a) << "\n";
    return 0;
}