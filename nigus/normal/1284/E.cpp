#pragma GCC optimize("O3")   //
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

const int MAXN = 100001;

struct pt{
    ll x,y;
};

vector<pt> P;

vector<ld> angs;

bool comp(ll i, ll j){
    return angs[i] < angs[j];
}
/*
pll dumb(vector<pt> PP, pt p0){
    ll a = 0;
    ll b = 0;
    trav(p, PP){
        if(p0.x*p.y - p0.y*p.x > 0)a++;
        if(p0.x*p.y - p0.y*p.x < 0)b++;
    }
    return {a,b};
}
*/
ll Q(ll i){
    vector<pt> P2;

    rep(c1,0,n){
        if(c1 != i){
            P2.push_back({P[c1].x - P[i].x, P[c1].y - P[i].y});

        }
    }
    ll ans = 0;
    angs.clear();
    vi kind, ind;

    vector<pt> P3;

    rep(i,0,sz(P2)){
        pt p = P2[i];
        angs.push_back(atan2(p.y, p.x));
        kind.push_back(0);
        angs.push_back(atan2(-p.y, -p.x));
        kind.push_back(1);
        ind.push_back(sz(ind));
        ind.push_back(sz(ind));
        P3.push_back(p);
        P3.push_back({-p.x, -p.y});
    }
    sort(all(ind), comp);

    ll a = 0;
    ll b = 0;

    trav(i, ind){
        if(kind[i] == 0){
            pt p = P3[i];
            pt p0 = P3[ind[0]];

            if(p0.x*p.y - p0.y*p.x > 0 || (p0.x*p.y - p0.y*p.x == 0 && kind[ind[0]] == 0)){
                a++;

            }
            else{
                b++;
            }
        }
    }

   // cerr << "START: " << P3[ind[0]].x << " " << P3[ind[0]].y << "  -   " << a << " " << b << "\n";

    trav(i, ind){
        if(kind[i] == 0){
            a--;
            ans += a*b;

            //pll ab = dumb(P2, P3[i]);
           // cerr << a << " " << b << "   -   " << ab.first << " " << ab.second << "   gfd\n";
           // if(a != ab.first || b != ab.second){
              //  cerr << a << " " << b << "   -   " << ab.first << " " << ab.second << "   OMG\n";
           // }

          //  cerr << a << " " << b << "   " << angs[i] << "   fdhs\n";
            b++;
        }
        else{
            a++;
            b--;
        }
       // cerr << a << " " << b << "   fdhs\n";
    }
   // cerr << ans <<   "   AAAA\n";
    return ans;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a >> b;
        P.push_back({a,b});
    }

    ll tot2 = 0;

    ll quantity = 0;
    rep(c1,0,n){
        quantity += Q(c1);
        tot2 += ((n-1)*(n-2)*(n-3)) / 6;
    }

    ll tot3 = (n * (n-1)*(n-2)*(n-3)) / 24;

   // cerr << "Q: " << quantity << "  " << tot2 << "  -  " << (quantity-tot2)/2 << "  gfsdjk\n";

    cout << ((quantity-tot2) * (n-4))/4 << "\n";

    return 0;
}