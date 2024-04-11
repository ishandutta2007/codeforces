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

vector<vl> cols(MAXN, vl());
vl MA,ind;

bool comp(int i, int j){
    return MA[i] > MA[j];
}

vi shift;
ll brute(ll i){
    if(i == min(n,m)){
        ll ans = 0;
        rep(c1,0,n){
            ll ma = 0;
            rep(c2,0,min(n,m)){
                ll b = ind[c2];
                ma = max(ma, cols[b][(c1+shift[c2])%n]);
            }
            ans += ma;
        }
        return ans;

    }
    ll ans = 0;
    rep(c1,0,n){
        shift.push_back(c1);
        ans = max(ans, brute(i+1));
        shift.pop_back();
    }
    return ans;
}

ll dp(ll taken, ll mask){

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        MA.clear();
        ind.clear();
        rep(c1,0,m){
            cols[c1].clear();
        }
        rep(c1,0,m){
            ind.push_back(c1);
            MA.push_back(0);
        }
        rep(c1,0,n){
            rep(c2,0,m){
                cin >> a;
                MA[c2] = max(MA[c2],a);
                cols[c2].push_back(a);
            }
        }
        sort(all(ind),comp);

        shift.clear();
        ll ans = brute(0);
/*
        rep(c1,1,(1 << min(n,m))){
            vi vals;
            rep(c2,0,min(n,m)){
                b = ind[c2];
                if((c1 & (1 << c2)) != 0){
                    rep(c3,0,n){
                        vals.push_back(cols[b][c3]);
                    }
                }
            }
            sort(all(vals));
            reverse(all(vals));
            a = 0;
            rep(c2,0,n){
                a += vals[c2];
            }
            ans = max(ans,a);
        }
        */
        cout << ans << "\n";
    }

    return 0;
}