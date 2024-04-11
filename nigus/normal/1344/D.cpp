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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vl A,B;

ll f(ll i, ll b){
    return b*(A[i] - b*b);
}

ll g(ll i, ll b){
    return A[i] - (3*b*b + 3*b + 1);
}

bool exact[MAXN] = {0};

ll getx(ll i, ll x){
    ll l = 0;
    ll r = A[i]+1;

    while(l < r-1){
        ll mid = (l+r)/2;
        if(g(i, mid) >= x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    exact[i] = (g(i,l) == x);
    return l;
}

ll totk(ll x){
    ll ans = 0;
    rep(c1,0,n){
        ans += getx(c1, x);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> k;
   // n = 100000;
   // k = 100000000000001;
    rep(c1,0,n){
        cin >> a;
        //a = 1000000000;
        A.push_back(a);
    }

    ll l = -4*big*big;
    ll r = 4*big*big;

    while(l < r-7){
        ll mid = l/2 + r/2;
       // cerr << l << " " << r << "\n";
        ll tt = totk(mid);
        if(tt >= k){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    while(totk(l+1) >= k){
        l++;
    }

    totk(l);

    ll ans = 0;
    vl B(n);
    rep(c1,0,n){
        B[c1] = getx(c1, l) - exact[c1];
        ans += B[c1];
    }

    ll tot = 0;

    //assert(ans <= k);
    rep(c1,0,n){
        if(exact[c1] && ans < k){
            ans++;
            B[c1]++;
        }
        cout << B[c1] << " ";
        tot += B[c1];
    }cout << "\n";
   // assert(tot == k);
/*
    ll sum = 0;
    ll tot = 0;
    rep(c1,0,n){
        sum += f(c1, B[c1]);
        tot += B[c1];
        assert(B[c1] <= A[c1]);
    }

    assert(tot == k);

    cerr << "TOT: " << tot << "\n";
    cerr << sum << "\n";
    */

    return 0;
}