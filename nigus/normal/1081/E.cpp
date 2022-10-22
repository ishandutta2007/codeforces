#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,d;
const ll big = 1000000007;
const ll mod = 998244353;

ll X[200003] = {0};
ll SX[200003] = {0};

bool sqr(ll i){
    ll st = ll(sqrt(i));
    for(ll c1 = -2; c1 <= 2; c1++){
        if((st+c1)*(st+c1) == i)return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;
   // n = 100000;
    bool fail = 0;
    ll lowest = 1;
    for(ll c1 = 1; c1 < n; c1 += 2){
        cin >> a;
       // a = rand();
        //a = 2*c1+1;
        X[c1] = a;
        ll mi = big;
        for(ll c2 = 1; c2*c2 <= a; c2++){
            if(a%c2 == 0){
                ll q = c2;
                ll p = a/q;
                if((p+q)%2 != 0)continue;

                ll a2 = (p+q)/2;
                ll a1 = p-a2;
                if(a1 >= lowest){
                    mi = min(mi,a2);
                }


            }
        }

        if(mi == big){
            fail = 1;
        }

        SX[c1] = mi*mi;
        lowest = mi+1;
    }

    if(fail){
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    bool debug = 0;
    ll sm = 0;

    for(ll c1 = 0; c1 < n; c1++){
        if(c1%2 == 1){
            cout << X[c1] << " ";
            sm += X[c1];
        }
        else{
            if(c1 == 0){
                    a = SX[c1+1]-X[c1+1];
            }
            else{
                a = SX[c1+1]-X[c1+1]-SX[c1-1];
            }
            cout << a <<" ";
            sm += a;
        }
        if(debug){
            assert(sqr(sm));
        }
    }

    return 0;
}