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

vi A,B;
vi on;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    string s;
    cin >> s;

    rep(c1,0,n){
        on.push_back(s[c1]-'0');
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    ll ans = 0;

    rep(c1,0,10000){
        rep(c2,0,n){
            if(c1 >= B[c2] && (c1-B[c2])%A[c2] == 0){
                on[c2] ^= 1;
            }
        }
        a = 0;
        rep(c2,0,n){
            a += on[c2];
        }
        ans = max(ans,a);
        //cerr << a << "\n";
    }
    cout << ans << "\n";

    return 0;
}