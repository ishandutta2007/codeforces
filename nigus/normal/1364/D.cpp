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

const int MAXN = 300001;

vector<vi> C(MAXN, vi());
vector<vi> C2(MAXN, vi());

int dist[MAXN] = {0};

bool mark[MAXN] = {0};

int PAR[MAXN] = {0};

void dfs(ll i){
    if(mark[i])return;
    mark[i] = 1;
    trav(j,C[i]){
        if(!mark[j]){
           C2[i].push_back(j);
           dist[j] = dist[i]+1;
           PAR[j] = i;
           dfs(j);
        }
    }
}

vi I,J;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m >> k;
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    PAR[0] = -1;
    dfs(0);

    int cyc1 = -1;
    int cyc2 = -1;
    rep(c1,0,n){
        trav(j, C[c1]){
            if(abs(dist[c1] - dist[j]) < k && abs(dist[c1] - dist[j]) > 1){
                cyc1 = c1;
                cyc2 = j;
            }
        }
    }
    if(cyc1 != -1){
        if(dist[cyc1] < dist[cyc2])swap(cyc1, cyc2);
        cout << "2\n";
        vi ANS;
        ANS.push_back(cyc1);
        while(cyc1 != cyc2){
            cyc1 = PAR[cyc1];
            ANS.push_back(cyc1);
        }
        cout << sz(ANS) << "\n";
        trav(y, ANS){
            cout << y+1 << " ";
        }cout << "\n";
        return 0;
    }

    rep(c1,0,n){
        if(dist[c1] < k){
            if(dist[c1]%2 == 0){
                I.push_back(c1);
            }
            else{
                J.push_back(c1);
            }
        }
    }

    cout << "1\n";

    if(sz(I) < sz(J)){
        rep(c1,0,(k+1)/2){
            cout << J[c1]+1 << " ";
        }cout << "\n";
        return 0;

    }

    rep(c1,0,(k+1)/2){
            cout << I[c1]+1 << " ";
        }cout << "\n";
        return 0;

    return 0;
}