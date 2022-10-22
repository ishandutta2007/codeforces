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

const ll MAXN = 100004;


vector<set<pii> > VS;

struct edge{
    ll u,v,w;
};

vector<edge> three(int i){
    vector<edge> res;
    if(i == -1 || sz(VS[i]) == 0)return res;
    auto it = VS[i].begin();
    rep(c1,0,3){
        if(it == VS[i].end())return res;
        res.push_back({i, (*it).second, (*it).first});
        it++;
    }
    return res;
}

ll three_score(ll i){
    vector<edge> ee = three(i);
    ll res = 0;
    if(sz(ee) < 3)return 10 * big;
    trav(e, ee){
        res += e.w;
    }
    return res;
}

map<ll,ll> weight;
set<pll> min_three;

ll hh(ll i, ll j){
    if(i > j)swap(i, j);
    return i*n+j;
}

set<pll> min_edges;

void rem(ll i){
    vector<edge> edges = three(i);
    ll score = 0;
    trav(e, edges){
        ll h = i*n + e.v;
        min_edges.erase({e.w, h});
        score += e.w;
    }
    if(sz(edges) < 3)score = 10 * big;
    min_three.erase({score, i});
}

void add(ll i){
    vector<edge> edges = three(i);
    ll score = 0;
    trav(e, edges){
        ll h = i*n + e.v;

        vector<edge> tv = three(e.v);
        bool found = 0;
        trav(y, tv){
            if(y.v == i || y.u == i)found = 1;
        }

        if(found)min_edges.insert({e.w, h});
        score += e.w;
    }
    if(sz(edges) < 3)score = 10 * big;
    min_three.insert({score, i});
}

void add_edge(ll i, ll j, ll w){
    weight[hh(i, j)] = w;
    rem(i);
    rem(j);
    VS[i].insert({w, j});
    VS[j].insert({w, i});
    add(i);
    add(j);
}

void rem_edge(ll i, ll j){
    ll w = weight[hh(i, j)];
    rem(i);
    rem(j);
    VS[i].erase({w, j});
    VS[j].erase({w, i});
    add(i);
    add(j);
}


edge to_edge(pll p){
    return {p.second/n, p.second%n, p.first};
}

void solve(){
    ll ans = 10*big;
    if(sz(min_three) > 0){
        auto it = min_three.begin();
        ans = (*it).first;
    }
    ll t3 = ans;

    edge smallest = to_edge(*(min_edges.begin()));

    vector<edge> edges = {};
    trav(y, three(smallest.u)){
        edges.push_back(y);
    }
    trav(y, three(smallest.v)){
        edges.push_back(y);
    }

    auto it = min_edges.begin();

    while(it != min_edges.end()){
        edge e = to_edge(*it);
        if(e.u != smallest.u && e.u != smallest.v && e.v != smallest.v && e.v != smallest.u){
            edges.push_back(e);
            break;
        }
        it++;
    }


    rep(c1,0,sz(edges)){
        rep(c2,c1+1,sz(edges)){
            edge e1 = edges[c1];
            edge e2 = edges[c2];
            if(e1.w + e2.w < ans && e1.u != e2.u && e1.v != e2.u && e1.u != e2.v && e1.v != e2.v){
                ans = e1.w + e2.w;
            }
        }
    }


    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    T = 1;
    rep(c4,0,T){
        cin >> n >> m;

        rep(c1,0,n){
            set<pii> temp;
            VS.push_back(temp);
        }

        rep(c1,0,m){
            cin >> a >> b >> c;
            a--;
            b--;
            add_edge(a, b, c);
        }

        cin >> q;
        solve();
        rep(c1,0,q){
            cin >> d;
            if(d == 0){
                cin >> a >> b;
                a--;
                b--;
                rem_edge(a, b);
            }
            else{
                cin >> a >> b >> c;
                a--;
                b--;
                add_edge(a, b, c);
            }

            solve();
        }
    }

    return 0;
}