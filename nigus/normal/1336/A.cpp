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

const int MAXN = 300001;

vector<vi> C(MAXN, vi());

ll DEP[MAXN] = {0};
ll PAR[MAXN] = {0};
ll DEG[MAXN] = {0};
ll DIRT[MAXN] = {0};

void dfs(ll i, ll par){
    PAR[i] = par;
    trav(j, C[i]){
        if(j != par){
            DEP[j] = DEP[i]+1;
            DEG[i]++;
            dfs(j,i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs(0,-1);
    priority_queue<pll> pq;
    rep(c1,0,n){
        if(DEG[c1] == 0)pq.push({DEP[c1],c1});
    }
    ll ans = 0;
    rep(c1,0,k){
        ans += pq.top().first;
        ll i = pq.top().second;
        pq.pop();
        if(PAR[i] != -1){
            ll j = PAR[i];
            DIRT[j] += (DIRT[i] + 1);
            DEG[j]--;
            if(DEG[j] == 0){
                pq.push({DEP[j] - DIRT[j], j});
            }
        }
    }
    cout << ans << "\n";

    return 0;
}