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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vl P;
        rep(c1,0,n){
            cin >> a;
            P.push_back(a);
        }
        vl ANS;
        rep(c1,0,n){
            if(c1 == 0 || c1 == n-1){
                ANS.push_back(P[c1]);
            }
            else{
                if(P[c1-1] < P[c1] && P[c1] > P[c1+1])ANS.push_back(P[c1]);
                if(P[c1-1] > P[c1] && P[c1] < P[c1+1])ANS.push_back(P[c1]);
            }
        }
        cout << sz(ANS) << "\n";
        trav(y, ANS){
            cout << y << " ";
        }cout << "\n";
    }



    return 0;
}