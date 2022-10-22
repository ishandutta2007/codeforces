#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,q,p;
ll T;

vector<vi> C(100001, vi());

ll vis = 0;
vi E;

ll mark[100001] = {0};

void dfs(ll i, ll par){
    bool leaf = 1;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            leaf = 0;
            vis++;
            dfs(a,i);
            break;
        }
    }
    if(leaf){
        E.push_back(i);
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;


    cin >> n;
    for(int c1 = 0; c1 < n-1; c1++){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            C[b].push_back(a);
    }

    ll md = 0;
    ll root = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(sz(C[c1]) > md){
            md = sz(C[c1]);
            root = c1;
        }
    }

    for(int c1 = 0; c1 < sz(C[root]); c1++){
        dfs(C[root][c1],root);
    }

    vis += sz(C[root]);
    if(vis == n-1){
        cout << "Yes\n";
        cout << sz(E) << "\n";
        for(int c1 = 0; c1 < sz(E); c1++){
            cout << root+1 << " " << E[c1]+1 << "\n";
        }
    }
    else{
        cout << "No\n";
    }

    return 0;
}