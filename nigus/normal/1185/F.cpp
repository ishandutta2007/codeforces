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

const ll MAXN = 2001;

vl A;
vl mask;
vector<vl> inds(512, vl());
bool comp(ll i, ll j){
    return A[i] < A[j];
}
ll F[512] = {0};
ll FS[512] = {0};
vi ind;

ll I[512] = {0};
ll J[512] = {0};
ll cost[512] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n >> m;
    rep(c1,0,n){
        cin >> a;
        b = 0;
        rep(c2,0,a){
            cin >> c;
            c--;
            b += (1 << c);
        }
        F[b]++;
    }
    rep(c1,0,512){
        rep(c2,0,512){
            if((c1|c2) == c1)FS[c1] += F[c2];
        }
    }

    rep(c1,0,m){
        cin >> c >> a;
        b = 0;
        A.push_back(c);
        rep(c2,0,a){
            cin >> d;
            d--;
            b += (1 << d);
        }
        inds[b].push_back(c1);
        mask.push_back(b);
    }
    rep(c1,0,512){
        sort(all(inds[c1]),comp);
        if(sz(inds[c1]) > 0)ind.push_back(inds[c1][0]);
        if(sz(inds[c1]) > 1)ind.push_back(inds[c1][1]);
    }

    ll a1 = -1;
    ll a2 = -1;
    ll people = -1;
    ll cc = big*big;

    rep(c1,0,sz(ind)){
        rep(c2,0,sz(ind)){
            a = ind[c1];
            b = ind[c2];
            if(a != b){
                c = A[a]+A[b];
                ll msk = (mask[a]|mask[b]);
                if(FS[msk] > people || (FS[msk] == people && c < cc)){
                    cc = c;
                    people = FS[msk];
                    a1 = a;
                    a2 = b;
                }
            }
        }
    }

    cout << a1+1 << " " << a2+1 << "\n";

    return 0;
}