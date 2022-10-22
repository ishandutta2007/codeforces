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

const ll MAXN = 200001;

vl W,A,B,I;
ll deg[MAXN];
ll pek[MAXN];


ll Q[MAXN] = {0};
vi ind;
ll ANS[MAXN] = {0};

ll par(ll i){
    while(i != pek[i]){i = pek[i];}
    return i;
}

ll ans = 0;

ll b2(ll x){
    return (x*(x-1))/2;
}

void merg(ll i, ll j){
    ll i2 = par(i);
    ll j2 = par(j);
    if(i2 != j2){
        ans -= b2(deg[i2])+b2(deg[j2]);
        ans += b2(deg[i2]+deg[j2]);
        if(deg[i2] < deg[j2])swap(i2,j2);
        deg[i2]+=deg[j2];
        pek[j2]=i2;
    }
}

bool comp(ll i, ll j){
    return Q[i] < Q[j];
}

bool comp2(ll i, ll j){
    return W[i] < W[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> q;

    if(n == 1){
        rep(c1,0,q){
            cout << "0 ";
        }cout << "\n";
        return 0;
    }

    rep(c1,0,n-1){
        cin >> a >> b >> c;
        a--;
        b--;
        A.push_back(a);
        B.push_back(b);
        W.push_back(c);
        I.push_back(c1);
    }
    sort(all(I),comp2);
    rep(c1,0,n){
        pek[c1] = c1;
        deg[c1] = 1;
    }

    rep(c1,0,q){
        cin >> a;
        Q[c1] = a;
        ind.push_back(c1);
    }

    sort(all(ind),comp);

    ll i = 0;

    I.push_back(-1);

    rep(c1,0,q){
        ll a = ind[c1];
        ll b = I[i];
        while(i < n-1 && W[b] <= Q[a]){
            merg(A[b],B[b]);
            i++;
            b = I[i];
        }
       ANS[a] = ans;
    }
    rep(c1,0,q){
        cout << ANS[c1] << " ";
    }cout << "\n";

    return 0;
}