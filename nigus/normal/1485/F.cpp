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

const int MAXN = 200001;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;

    rep(c4,0,T){
        ll DP[2] = {0};

        cin >> n;
        map<ll,ll> M;
        b = 0;
        rep(c1,0,n){
            cin >> a;
            if(c1 == 0){
                DP[0] = 0;
                DP[1] = 1;
                M[0] = 1;
            }
            else{
                ll sum = DP[0]+DP[1];
                DP[0] = sum;
                DP[1] = sum;
                ll look = b;
                if(M.find(look) != M.end()){
                    DP[1] -= M[look];
                }
                DP[0] %= big;
                DP[1] += 2*big;
                DP[1] %= big;

                if(M.find(b) == M.end())M[b] = 0;
                M[b] += DP[1];
                M[b] %= big;

            }
            b += a;
        }
        cout << (DP[0]+DP[1])%big << "\n";
    }

    return 0;
}