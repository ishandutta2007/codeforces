#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 100001;

ll dist[MAXN] = {0};
ll pek[MAXN] = {0};
vector<vl> C(MAXN, vl());

ll madist = -1;
ll start = 0;

ll dfs1(ll i, ll par){
    if(madist < dist[i])start = i;
    madist = max(madist, dist[i]);
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            dist[a] = dist[i] + 1;
            pek[a] = i;
            dfs1(a,i);
        }
    }
}

ll D[MAXN] = {0};

bool verify(ll i, ll par, ll d){
    if(D[d] == 0)D[d] = sz(C[i]);
    if(D[d] != sz(C[i]))return 0;
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            bool temp = verify(a,i,d+1);
            if(!temp)return 0;
        }
    }
    return 1;
}

ll dd = 0;

ll get_leaf(ll i, ll par){
    if(sz(C[i]) == 1)return i;
    if(sz(C[i]) > 2)return -1;
    if(C[i][0] == par){
        dd++;
        return get_leaf(C[i][1], i);
    }
    dd++;
    return get_leaf(C[i][0], i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n;
    ll leaf = 0;
    int madeg = 0;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    rep(c1,0,n){
        if(sz(C[c1]) == 1)leaf = c1;
        madeg = max(madeg, sz(C[c1]));
    }
    if(madeg <= 2){
        cout << leaf+1;
        return 0;

    }
    dfs1(leaf,-1);

    leaf = start;
    rep(c1,0,n){
        dist[c1] = 0;
        madist  = -1;
    }
    dfs1(leaf, -1);
    vl cands;


    cands.push_back(start);
    rep(c1,0,madist/2){
        start = pek[start];
    }

    cands.push_back(start);
    cands.push_back(leaf);

    vector<pii> cc;
    set<ll> seen;

    rep(c1,0,sz(C[start])){
        a = C[start][c1];
        dd = 0;
        b = get_leaf(a, start);
        if(b != -1 && seen.find(dd) == seen.end() && sz(cands) < 10){
            cands.push_back(b);
        }
        if(b != -1)seen.insert(dd);
    }

    rep(c1,0,sz(cands)){
        //cerr << cands[c1] << "\n";
        rep(c2,0,n)D[c2] = 0;
        if(verify(cands[c1],-1,0)){
            cout << cands[c1] + 1 << "\n";
            return 0;
        }
    }

    cout << "-1\n";


    return 0;
}