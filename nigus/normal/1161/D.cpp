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

string s;
vector<vi> C(3001, vi());
vector<vi> CX(3001, vi());
int col[3001] = {0};

bool fail = 0;

bool dfs(ll i, ll c){
    if(col[i] != -1 && col[i] != c){fail = 1;return 0;}
    if(col[i] != -1)return 1;

    col[i] = c;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        ll c2 = CX[i][c1];
        dfs(a, c^c2);
    }
}

void link(ll i, ll j, ll x){
    C[i].push_back(j);
    C[j].push_back(i);
    CX[i].push_back(x);
    CX[j].push_back(x);
}

ll solve(ll l){
    for(int c1 = 0; c1 < 3001; c1++){
        C[c1].clear();
        CX[c1].clear();
        col[c1] = -1;
    }
    fail = 0;

    for(int c1 = 0; c1 < m; c1++){
        link(c1,m-c1-1,0);
    }

    for(int c1 = 0; c1 < l; c1++){
        link(m+c1,m+l-c1-1,0);
    }

    for(int c1 = 0; c1 < l; c1++){
        if(s[c1] != '?'){
            link(c1,m+c1,s[c1]-'0');
        }
    }

    link(0,2*m+1,0);
    link(m-1,2*m+1,0);
    link(m,2*m+1,0);
    link(m+l-1,2*m+1,0);

    for(int c1 = l; c1 < m; c1++){
        if(s[c1] != '?'){
            link(c1, 2*m + s[c1]-'0', 0);
        }
    }

    ll temp = 1;

    dfs(2*m,0);
    dfs(2*m+1,1);

    if(fail)return 0;

    for(int c1 = 0; c1 < m+l; c1++){
        if(col[c1] == -1){
            dfs(c1,0);
            if(fail)return 0;
            temp *= 2;
            temp %= mod;
        }
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> s;
    reverse(all(s));
    m = s.length();
    ll ans = 0;
    for(int c1 = 1; c1 < m; c1++){
        ans += solve(c1);
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}