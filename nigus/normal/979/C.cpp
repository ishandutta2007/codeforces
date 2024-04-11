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

ll n,m,q;
ll T;

vector<vi> C(300001, vi());

ll A = 1;
ll B = 0;
ll x,y;
ll dfs2(int i, int par){
    ll ans = 1;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        if(a != par){
            ans += dfs2(a,i);
        }
    }
    return ans;
}

bool dfs(int i, int par){
    bool b = 0;
    if(i == y){
        B = dfs2(i,par);
        return 1;
    }
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        if(a != par){
            bool c = dfs(a,i);
            b |= c;
            if(i == x && c == 0){
                A += dfs2(a,i);
            }
        }
    }
    return b;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> x >> y;
    x--;
    y--;
    for(int c1 = 0; c1 < n-1; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs(x,-1);
    cout << n*(n-1)-A*B << "\n";
    return 0;
}