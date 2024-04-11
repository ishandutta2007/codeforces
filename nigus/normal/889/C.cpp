#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,h,T;

ll DP[1000001] = {0};
ll nk = 1;

ll FAC[1000001] = {0};
ll INV[1000001] = {0};

ll mod(ll i){
    if(i < 0)return mod(big-mod(-i));
    if(i < big)return i;
    return i%big;
}

ll upp(ll i, ll j){

if(j == 0)return 1;
if(j%2 == 0){
    ll h = upp(i,j/2);
    return mod(h*h);
}
return mod(i*upp(i,j-1));
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> k;

    if(k >= n){
        ll f = 1;
        for(ll c1 = 0; c1 < n; c1++){
            f *= c1+1;
            f %= big;

        }
        cout << 0 << "\n";
    }
    else{

        DP[0] = 1;
        DP[1] = 1;
        a = 1;
        for(ll c1 = 0; c1 < 1000001; c1++){
            FAC[c1] = a;
            a *= c1+1;
            a %= big;
        }

        INV[1000000] = upp(FAC[1000000], big-2);
        for(ll c1 = 1000000; c1 > 0; c1--){
            INV[c1-1] = (INV[c1]*c1)%big;
        }

        ll old = 1;
        for(ll c1 = 1; c1 < n+1; c1++){
            ll ny = old;
            old *= c1;
            old += ny;
            old %= big;
            DP[c1] = ny;
            if(c1 >= k){
                ll i = 1;
                if(c1 > k){
                    i = INV[c1-k];
                }
                old -= (((FAC[c1]*i)%big)*DP[c1-k])%big;
                old += 2*big;
                old %= big;
            }
        }

        ll ans = 0;
        for(ll c1 = 0; c1 < n; c1++){
            ans += ((FAC[n-1]*INV[n-c1-1])%big)*((DP[n-c1-1])%big);

            //cout << (((FAC[n-1]*INV[n-c1-1])%big)*((DP[n-c1-1])%big))%big << " ";

            ans %= big;
        }

        //cout << ans << "\n";

        ans = FAC[n]-ans;
        ans += 2*big;
        ans %= big;
        cout << ans << "\n";

    }



    return 0;
}