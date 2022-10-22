
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

const int MAXN = 200001;

ll balance[MAXN] = {0};

vi N,P;

vl A,B,W;

void add_edge(ll i, ll j){
    ll mi = min(balance[i], balance[j]);
    A.push_back(i);
    B.push_back(j);
    W.push_back(mi);
    balance[i] -= mi;
    balance[j] -= mi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;


    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b >> c;
        a--;b--;
        balance[a] -= c;
        balance[b] += c;
    }

    rep(c1,0,n){
        if(balance[c1] > 0){
            P.push_back(c1);
        }
        if(balance[c1] < 0){
            balance[c1] *= -1;
            N.push_back(c1);
        }
    }
    ll r = 0;
    trav(y,N){
        while(balance[y] > 0){
            add_edge(y,P[r]);
            if(balance[P[r]] == 0)r++;
        }
    }

    cout << sz(A) << "\n";
    rep(c1,0,sz(A)){
        cout << A[c1]+1 << " " << B[c1]+1 << " " << W[c1] << "\n";
    }
    return 0;
}