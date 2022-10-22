#pragma GCC optimize("O3")
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

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vector<vi> C(MAXN, vi());

vi special;

ll dist[MAXN][2] = {0};
bool mark[MAXN][2] = {0};

vl sd1, sd2;

void bfs(int mode){
    queue<ll> Q;
    if(mode == 0){
        Q.push(0);
        dist[0][mode] = 1;
    }
    else{
        Q.push(n-1);
        dist[n-1][mode] = 1;
    }

    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        if(!mark[a][mode]){
            mark[a][mode] = 1;
            trav(j, C[a]){
                if(dist[j][mode] == 0){
                    dist[j][mode] = dist[a][mode]+1;
                    Q.push(j);
                }
            }
        }
    }
}

bool comp(ll i, ll j){
    return dist[i][0] < dist[j][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> k;
    rep(c1,0,k){
        cin >> a;
        a--;
        special.push_back(a);
    }
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    bfs(0);
    bfs(1);

    sort(all(special), comp);

    ll ma2 = 0;

    ll ans = 0;

    for(int c1 = k-1; c1 >= 0; c1--){
        int i = special[c1];
        if(c1 < k-1){
            ans = max(ans, 1 + dist[i][0] + ma2 - 2);
        }
        ma2 = max(ma2, dist[i][1]);
    }
   // cerr << ans << "\n";
    cout << min(ans, dist[n-1][0]-1) << "\n";

    return 0;
}