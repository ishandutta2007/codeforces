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

vector<ll> divs;
vector<vector<ll> > C(200004 , vector<ll>());
vector<vector<ll> > C2(200004 , vector<ll>());
vector<ll> W;
bool mark[200004] = {0};

ll DP[200004] = {0};

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

ll dp(ll i){
if(DP[i] != -1)return DP[i];
ll ma = 0;
for(ll c1 = 0; c1 < C2[i].size(); c1++){
    ll a = C2[i][c1];
    ma = max(dp(a), ma);
}
DP[i] = W[i]+ma;
return DP[i];
}

ll upp(ll i, ll j, ll mod){
if(j == 0)return 1ll;
if(j%2 == 0){
    ll h = upp(i,j/2,mod);
    return (h*h)%mod;
}
return (upp(i,j-1,mod)*i)%mod;

}

ll inv(ll a, ll b){
    return 1ll<a ? b - inv(b%a,a)*b/a : 1ll;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n >> m;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        mark[a] = 1;
    }

    if(m == 1){

        cout << "1\n0";

    }
    else{
    for(ll c1 = 0; c1 < m+1; c1++){
        W.push_back(0);
    }

    for(ll c1 = 1; c1 < m; c1++){
        if(m%c1 == 0){
            divs.push_back(c1);
            for(ll c2 = 0; c2 < divs.size()-1; c2++){
                if(c1%divs[c2] == 0){
                    C2[divs[c2]].push_back(c1);
                }
            }
        }
        ll g = gcd(m,c1);
        C[g].push_back(c1);
        /*
        ll i;
        for(ll c2 = 0; c2 < divs.size(); c2++){
            if(divs[c2] == g){
                i = c2;
                break;
            }
        }
        */
        W[g]++;
        if(mark[c1])W[g]--;
        DP[c1] = -1;
    }
    DP[0] = -1;
    ll ma = 0;
    ll mags = 0;
    for(ll c1 = 1; c1 < m; c1++){
        ll g = gcd(c1,m);
         //g = c1;
        ll d = dp(g);
        if(d > ma){
            ma = d;
            mags = g;
        }
    }

    vector<ll> A;
    vector<ll> B;
    ll i = mags;

    while(1 == 1){
        A.push_back(i);
        for(ll c1 = 0; c1 < C[i].size(); c1++){
            if(!mark[C[i][c1]])B.push_back(C[i][c1]);
        }
        ll ma2 = 0;
        ll i2 = i;
        for(ll c1 = 0; c1 < C2[i2].size(); c1++){
            a = C2[i2][c1];
            if(dp(a) > ma2){
                ma2 = dp(a);
                i = a;
            }
        }
        if(i == i2)break;
    }

    if(!mark[0]){
        ma++;
        B.push_back(0);
    }

    cout << B.size() << "\n";
     ll prod = 1;
    for(ll c1 = 0; c1 < ma; c1++){
        if(c1 == 0 || B[c1] == 0){
            prod *= B[c1];
            prod %= m;
            cout << B[c1]%m << " ";
        }
        else{

            ll g1 = gcd(B[c1-1],m);
            ll g2 = gcd(B[c1],m);

            ll prev = B[c1-1];

            ll m2 = m/g1;
            ll i2 = prev/g1;
            ll j2 = B[c1]/g1;

            ll x2 = (inv(i2,m2) * j2)%m2;

            ll x = (x2)%m;

            prod *= (x)%m;
            prod %= m;

            cout << (x)%m  << " ";

        }
    }
    }
    return 0;
}