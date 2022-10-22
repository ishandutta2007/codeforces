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

int DX[6] = {1, 0, -1, -1, 0, 1};
int DY[6] = {1, 1, 0, -1, -1, 0};
ll cost[6] = {0};
ll x,y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> T;

    rep(_,0,T){
        cin >> x >> y;
        rep(c1,0,6){
            cin >> c;
            cost[c1] = c;
        }
        rep(c1,0,6){
            c = (cost[(c1+5)%6] + cost[(c1+1)%6]);
            cost[c1] = min(cost[c1], c);
        }
        ll ans = big*big;
        rep(c1,0,6){
            a = c1;
            b = (c1+1)%6;
            ll x1 = DX[a];
            ll x2 = DX[b];
            ll y1 = DY[a];
            ll y2 = DY[b];
            bool bad = 0;

            ll d2 = 0;
            ll d1 = 0;

            if(x1 != 0){
                ll D = x1*y2 - y1*x2;
                ll D2 = x1*y - x*y1;
                if(abs(D2) % abs(D) != 0)bad = 1;
                d2 = D2/D;
                d1 = (x-d2*x2)/x1;
                if(abs(x-d2*x2) % abs(x1) != 0)bad = 1;
            }
            else{
                ll D = x2*y1 - y2*x1;
                ll D2 = x2*y - x*y2;
                if(abs(D2) % abs(D) != 0)bad = 1;
                d1 = D2/D;
                d2 = (x-d1*x1)/x2;
                if(abs(x-d1*x1) % abs(x2) != 0)bad = 1;
            }

            if(d1 >= 0 && d2 >= 0 && !bad){
                ans = cost[a]*d1 + cost[b]*d2;
            }

        }
        cout << ans << "\n";
    }

    return 0;
}