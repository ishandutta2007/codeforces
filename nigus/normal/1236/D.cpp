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

vector<vi> R(MAXN, vi());
vector<vi> C(MAXN, vi());

ll DX[4] = {0,1,0,-1};
ll DY[4] = {1,0,-1,0};

struct pt{
    int x,y;
};

ll solve(pt MI, pt MA, pt now, ll dir, bool start){
    ll x = now.x;
    ll y = now.y;

   // cerr << x+1 << " " << y+1 << "  dir: " << dir+1 << "\n";

    if(dir == 0){
        pt nxt = {x,MA.y};
        trav(y2, R[x]){
            if(y2 > y)nxt.y = min(nxt.y, y2);
        }
        nxt.y -= 1;

        if(nxt.y == y && !start)return 0;

        return nxt.y - y + solve({MI.x+1, MI.y}, {MA.x, nxt.y+1}, nxt,  (dir+1)%4, 0);
    }

    if(dir == 1){
        pt nxt = {MA.x, y};
        trav(x2, C[y]){
            if(x2 > x)nxt.x = min(nxt.x, x2);
        }
        nxt.x -= 1;

        if(nxt.x == x)return 0;

        return nxt.x - x + solve({MI.x, MI.y}, {nxt.x+1 , MA.y - 1}, nxt,  (dir+1)%4, 0);
    }

    if(dir == 2){
        pt nxt = {x, MI.y - 1};
        trav(y2, R[x]){
            if(y2 < y)nxt.y = max(nxt.y, y2);
        }
        nxt.y += 1;

        if(nxt.y == y)return 0;

        return y - nxt.y + solve({MI.x, nxt.y}, {MA.x - 1 , MA.y}, nxt,  (dir+1)%4, 0);
    }

    if(dir == 3){
        pt nxt = {MI.x - 1, y};
        trav(x2, C[y]){
            if(x2 < x)nxt.x = max(nxt.x, x2);
        }
        nxt.x += 1;

        if(nxt.x == x)return 0;

        return x - nxt.x + solve({nxt.x, MI.y+1}, {MA.x, MA.y}, nxt,  (dir+1)%4, 0);
    }

    return 432;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> k;
    rep(c1,0,k){
        cin >> a >> b;
        a--;
        b--;
        R[a].push_back(b);
        C[b].push_back(a);
    }
    rep(c1,0,n){
        sort(all(R[c1]));
    }
    rep(c1,0,m){
        sort(all(C[c1]));
    }
    ll thing = solve({0,0}, {n,m}, {0,0}, 0, 1);

    if(thing + 1 == n*m - k){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}