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

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 200001;

vector<vl> C(2,vl());
ll N[2] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> k;
    string s;
    cin >> s;
    rep(c1,0,n){
        C[s[c1]-'0'].push_back(c1);
    }
    rep(c1,0,2){
        N[c1] = sz(C[c1]);
    }

    if(N[0] == 0 || N[1] == 0){
        cout << "tokitsukaze\n";
        return 0;
    }

    if(min(C[0][N[0]-1] - C[0][0] + 1 , C[1][N[1]-1] - C[1][0] + 1) <= k){
        cout << "tokitsukaze\n";
        return 0;
    }
    if(C[0][N[0]-1] - C[0][0] + 1 == k+1 && C[1][N[1]-1] - C[1][0] + 1 == k+1 && (C[0][0] < C[1][N[1]-1] && C[1][0] < C[0][N[0]-1] )){
        cout << "quailty\n";
        return 0;
    }
    cout << "once again\n";




    return 0;
}