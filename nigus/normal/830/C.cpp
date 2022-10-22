#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vl A;

vl X,Y,ind;
unordered_set<ll> S;

bool comp(int i, int j){
    return X[i] < X[j];
}

ll f(ll d){
    ll ans = 0;
    rep(c1,0,n){
        ans += d-1 - (A[c1]-1)%d;
    }
    return ans;
}

ll bs(ll d){
    ll l = d;
    ll r = 1000000000005;
    while(l < r-1){
        ll mid = (l+r)/2;
        if(f(mid) <= k){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));
    const ll lim = 37000;

    rep(c1,1,lim+1){
        X.push_back(c1);
        Y.push_back(f(c1));
        ind.push_back(sz(ind));
        S.insert(c1);
    }

    rep(c1,0,n){
        rep(c2,1,lim){
            a = (A[c1] + c2 - 1) / c2;
            if(S.find(a) != S.end())continue;
            X.push_back(a);
            Y.push_back(f(a));
            ind.push_back(sz(ind));
            S.insert(a);
        }
    }

    sort(all(ind), comp);

    ll j = -1;
    rep(c1,0,sz(ind)){
        ll i = ind[c1];
        if(Y[i] <= k)j = X[i];
    }

    cout << bs(j) << "\n";

    return 0;
}