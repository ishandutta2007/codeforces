#pragma GCC optimize("O3")

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

const int MAXN = 1007;

ll gcd(ll i, ll j){
    i = abs(i); j = abs(j);
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        int F[3] = {0};
        cin >> F[0] >> F[1] >> F[2];
        int ans = 0;
        rep(mask,0,(1 << 7)){
            int F2[3] = {0};
            int ss = 0;
            rep(dish,0,7){
                if((mask&(1 << dish)) != 0){
                    ss++;
                    rep(person,0,3){
                        if(((dish+1)&(1 << person)) != 0){
                            F2[person]++;
                            if(F2[person] > F[person])ss = -121212;
                        }
                    }
                }
            }
            ans = max(ans, ss);
        }
        cout << ans << "\n";
    }
    return 0;
}