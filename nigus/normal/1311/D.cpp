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

const int MAXN = 300001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> a >> b >> c;
        ll ans = big;
        ll A,B,C;
        rep(c1,1,10001){
            for(int c2 = c1; c2 <= 20000; c2 += c1){
                d = abs(a-c1) + abs(b-c2);
                ll cm = c%c2;
                ll dc = cm;
                ll cc = (c/c2)*c2;
                if(cc == 0 || 2*dc > c2){
                    cc += c2;
                    dc = c2-dc;
                }
                d += dc;
                if(d < ans){
                    ans = d;
                    A = c1;
                    B = c2;
                    C = cc;
                }
            }
        }
        cout << ans << "\n" << A << " " << B << " " << C << "\n";
    }

    return 0;
}