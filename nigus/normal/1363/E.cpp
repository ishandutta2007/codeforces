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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

vector<vi> C(MAXN, vi());

vl A,W;

void dfs1(ll i, ll par){
    trav(y,C[i]){
        if(y != par){
            W[y] = min(W[y], W[i]);
            dfs1(y,i);
        }
    }
}

ll N[MAXN][2] = {0};

ll dfs2(ll i, ll par){
    ll ans = 0;
    trav(y, C[i]){
        if(y != par){
            ans += dfs2(y, i);
            N[i][0] += N[y][0];
            N[i][1] += N[y][1];
        }
    }

    if(A[i] != -1){
        N[i][A[i]]++;
    }

    ll mi = min(N[i][0], N[i][1]);

    ans += 2*mi*W[i];
    N[i][0] -= mi;
    N[i][1] -= mi;
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
        cin >> a >> b >> c;
        if(c == b){
            A.push_back(-1);
        }
        else{
            A.push_back(c);
        }
        W.push_back(a);
    }
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs1(0,-1);
    ll ans = dfs2(0,-1);

    if(N[0][0]+N[0][1] > 0){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }


    return 0;
}