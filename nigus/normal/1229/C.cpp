#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
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

vector<vi> C(MAXN, vi());


ll ans = 0;

vector<vi> INS(MAXN, vi());

ll sumout[MAXN] = {0};
ll out[MAXN] = {0};
ll NUM[MAXN] = {0};

void update(ll i, ll x){
    ans -= sz(INS[i]) * out[i];
    ans -= sumout[i];
    ll newsum = 0;
    trav(y,INS[i]){
        newsum += out[y]-1;
        ans -= sz(INS[y]);
        INS[y].push_back(i);
        out[y]--;
        sumout[y] -= out[i];
    }


    //cerr << sumout[i] << " " << sz(INS[i]) * out[i] << " " << newsum << "\n";

    sumout[i] += newsum;
    ans += sumout[i];
    INS[i].clear();
    out[i] = sz(C[i]);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;
    //n = 100000;
    //m = 99999;
    rep(c1,0,m){
        cin >> a >> b;
       // a = n;
        //b = c1+1;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);

    }
    rep(c1,0,n){
        NUM[c1] = c1;
    }

    rep(c1,0,n){
        trav(y,C[c1]){
            if(NUM[y] > NUM[c1]){
                INS[c1].push_back(y);
            }
            else{
                out[c1]++;
            }
        }
    }
    rep(c1,0,n){
        trav(y,C[c1]){
            if(NUM[y] < NUM[c1]){
                sumout[c1] += out[y];
            }
        }
        ans += (sz(C[c1])-sz(INS[c1])) * (sz(INS[c1]));
    }



    cin >> q;
   // q = 100000;

    rep(c1,0,q){
        cin >> a;

       // a = random2()%n + 1;
       // a = n;
        cout << ans << "\n";
        update(a-1,n+c1);
    }
    cout << ans << "\n";

    return 0;
}