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

const ll MAXN = 1004;

vector<vi> C(MAXN, vi());

int level[MAXN] = {0};
int PAR[MAXN] = {0};
vi ind;
vector<vi> edge(3, vi());

void dfs(ll i, ll par){
    PAR[i] = par;
    trav(y, C[i]){
        if(y != par){
            level[y] = (level[i]+1);
            edge[level[y]%3].push_back(y);
            dfs(y, i);
        }
    }
}

bool comp(int i, int j){
    return sz(edge[i]) > sz(edge[j]);
}

bool comp2(int i, int j){
    return level[i] < level[j];
}

ll ask(ll lvl, ll L, ll R){

    set<int> v;

    if(lvl == -1){
        rep(c1,0,n){
            v.insert(c1);
        }
    }
    else{
        rep(c1,L,R){
            v.insert(edge[lvl][c1]);
            v.insert(PAR[edge[lvl][c1]]);
        }
    }

    if(sz(v) == 0)return -1;

    cout << "? " << sz(v) << " ";
    trav(y, v){
        cout << y+1 << " ";
    }cout << "\n";
    fflush(stdout);

    ll res;
    cin >> res;
    return res;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    rep(c1,0,3){
        ind.push_back(c1);
    }
    dfs(0, -1);
    sort(all(ind), comp);

    ll ma = ask(-1,0,0);

    ll good = -1;
    if(ask(ind[0], 0, sz(edge[ind[0]])) == ma){
        good = ind[0];
    }
    else{
        if(ask(ind[1], 0, sz(edge[ind[1]])) == ma){
            good = ind[1];
        }
        else{
            good = ind[2];
        }
    }


    ll L = 0;
    ll R = sz(edge[good]);
    sort(all(edge[good]), comp2);

    while(L < R-1){
        ll MID = (L+R)/2;
        ll tmp = ask(good, L, MID);

        if(tmp == ma){
            R = MID;
        }
        else{
            L = MID;
        }
    }

    cout << "! " << edge[good][L]+1 << " " << PAR[edge[good][L]]+1 << "\n";


    return 0;
}