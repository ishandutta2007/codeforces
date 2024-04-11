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

struct pt{
    ll x,y;
};

vector<pt> light;
vector<pt> P;

vector<vector<pt> > penalty(2001, vector<pt>());

bool comp(pt p1, pt p2){
    if(p1.x == p2.x)return p1.y > p2.y;
    return p1.x < p2.x;
}

ll PEN[1000012] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m;

    rep(c1,0,n){
        cin >> a >> b;
        P.push_back({a,b});
    }
    rep(c1,0,m){
        cin >> a >> b;
        light.push_back({a+1,b+1});
    }

    rep(c1,0,n){
        rep(c2,0,m){
            ll dx = light[c2].x - P[c1].x;
            ll dy = light[c2].y - P[c1].y;
            if(dx > 0 && dy > 0){
                penalty[c1].push_back({dx,dy});
            }
        }
        sort(all(penalty[c1]), comp);

        ll maxy = 0;
        for(int c3 = sz(penalty[c1])-1; c3 >= 0; c3--){
            penalty[c1][c3].y = max(maxy, penalty[c1][c3].y);
            maxy = penalty[c1][c3].y;
        }
        if(sz(penalty[c1]) > 0){

            rep(c2,0,sz(penalty[c1])){
                int x = penalty[c1][c2].x-1;
                PEN[x] = max(PEN[x], penalty[c1][c2].y);
            }

            /*
            PEN[0] = max(PEN[0], penalty[c1][0].y);
            ll prev = penalty[c1][0].y;
            rep(c2,1,sz(penalty[c1])){
                PEN[penalty[c1][c2-1].x] -= penalty[c1][c2-1].y - penalty[c1][c2].y;
            }
            ll last = sz(penalty[c1])-1;
            PEN[penalty[c1][last].x] -= penalty[c1][last].y;
            */
        }
    }

    ll maxy = 0;
    for(int c1 = 1000001; c1 >= 0; c1--){
        PEN[c1] = max(PEN[c1], maxy);
        maxy = PEN[c1];
    }

    ll ans = big;

    ll y = 0;
    rep(c1,0,1000001){
      /*  if(c1 < 11){
            cerr << c1 << ": " << PEN[c1] << "\n";

        }*/
        y = PEN[c1];
        ans = min(ans, c1+y);
    }

    cout << ans << "\n";

    return 0;
}