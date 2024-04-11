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

const int MAXN = 500001;

vl both, A, B;

vl CSA, CSB;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> k;

    rep(c1,0,n){
        cin >> a >> b >> c;
        if(b+c == 2){
            both.push_back(a);
        }
        else{
            if(b == 1){
                A.push_back(a);
            }
            if(c == 1){
                B.push_back(a);
            }
        }
    }
    sort(all(both)); sort(all(A)); sort(all(B));

    CSA.push_back(0);
    rep(c1,0,sz(A)){
        CSA.push_back(CSA[c1]+A[c1]);
    }
    CSB.push_back(0);
    rep(c1,0,sz(B)){
        CSB.push_back(CSB[c1]+B[c1]);
    }

    ll ans = big*big;

    ll tot = 0;

    rep(c1,0,sz(both)+1){
        if(c1 > k)break;
        ll rem = k-c1;
        if(rem >= sz(CSA) || rem >= sz(CSB)){if(c1 == sz(both))break;tot += both[c1];continue;}
        ll temp = tot + CSA[rem] + CSB[rem];
        ans = min(ans,temp);
        if(c1 == sz(both))break;
        tot += both[c1];
    }
    if(ans == big*big){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }


    return 0;
}