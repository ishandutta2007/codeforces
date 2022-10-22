
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

const int MAXN = 500001;

vector<vi> C(MAXN, vi());

ll L[MAXN] = {0};
ll R[MAXN] = {0};

ll goal = 0;

void solve(ll i, ll par){
    if(L[i] == goal)goal++;
    vi V;
    trav(y, C[i]){
        if(y != par){
            V.push_back(y);
            L[y] = goal;
            goal++;
        }
    }
    if(sz(V) == 0){
        R[i] = goal;
        goal++;
    }
    else{
        reverse(all(V));
        R[i] = goal;
        goal++;
        trav(y, V){
            solve(y,i);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
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
    solve(0,-1);
    rep(c1,0,n){
        cout << L[c1]+1 << " " << R[c1]+1 << "\n";
    }

    return 0;
}