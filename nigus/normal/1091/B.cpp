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
const ll big2 = 998244353;

vector<pii> X;
vector<pii> X2;
vector<pii> X3;

bool test(ll x, ll y){
    for(int c1 = 0; c1 < n; c1++){
        X3[c1] = {x-X2[c1].first,y-X2[c1].second};
    }
    sort(all(X3));
    bool yes = 1;
    for(int c1 = 0; c1 < n; c1++){
        if(X3[c1] != X[c1])return 0;
    }
    return 1;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        X.push_back({a,b});
    }
    sort(all(X));
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        X2.push_back({a,b});
        X3.push_back({0,0});
    }

    for(int c1 = 0; c1 < n; c1++){
        ll x = X[0].first+X2[c1].first;
        ll y = X[0].second+X2[c1].second;
        if(test(x,y)){
            cout << x << " " << y << "\n";
            break;
        }
    }

    return 0;
}