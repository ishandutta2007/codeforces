#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 200001;

unordered_map<ll,ll> M;
vl A,B,F;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    ll I;

    cin >> n >> I;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        if(M.find(a) == M.end()){
            M[a] = 0;
            B.push_back(a);
        }
        M[a]++;
    }
    m = sz(B);
    sort(all(B));
    rep(c1,0,sz(B)){
        F.push_back(M[B[c1]]);
    }

    I *= 8;

    k = I/n;

    if(k > 20){
        cout << "0\n";
        return 0;
    }

    ll K = (1ll << k);
    if(K >= m){
        cout << "0\n";
        return 0;
    }

    ll sum = 0;
    rep(c1,0,K){
        sum += F[c1];
    }
    ll ans = n;
    ans = min(ans, n-sum);
    rep(c1,K,m){
        sum += F[c1];
        sum -= F[c1-K];
        ans = min(ans,n-sum);
    }
    cout << ans << "\n";

    return 0;
}