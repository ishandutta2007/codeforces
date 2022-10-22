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

const int MAXN = 101;
vector<vl> C(MAXN,vl());

ll dist[MAXN][MAXN] = {0};
vl P;

void bfs(ll i){
    queue<ll> Q;
    Q.push(i);
    dist[i][i] = 1;
    while(!Q.empty()){
        ll a = Q.front();
        Q.pop();
        rep(c1,0,sz(C[a])){
            ll b = C[a][c1];
            if(dist[i][b] == 0){
                dist[i][b] = dist[i][a]+1;
                Q.push(b);
            }
        }
    }
}

int DP[1000001] = {0};
int NEX[1000001] = {0};
int LAST[MAXN] = {0};

void dp(){
    rep(c1,0,n){
        LAST[c1] = -1;
    }
    per(c1,m,0){
        if(c1 == m-1){
            DP[c1] = 1;
            NEX[c1] = m;
            LAST[P[c1]] = c1;
            continue;
        }
        DP[c1] = DP[c1+1]+1;
        NEX[c1] = c1+1;
        int a = P[c1];
        rep(c2,0,n){
            if(LAST[c2] != -1 && dist[a][c2]-1 == LAST[c2]-c1){
              //  cerr << c1+1 << " " << c2+1 << "\n";
                int temp = DP[LAST[c2]]+1;
                if(temp < DP[c1]){
                    DP[c1] = temp;
                    NEX[c1] = LAST[c2];
                }
            }
        }
        LAST[a] = c1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,n){
            if(s[c2] == '1'){
                C[c1].push_back(c2);
            }
        }
    }
    cin >> m;
    rep(c1,0,m){
        cin >> a;
        P.push_back(a-1);
    }
    rep(c1,0,n){
        bfs(c1);
    }
    dp();
    a = 0;
    cout << DP[0] << "\n";
    while(a != m){
        cout << P[a]+1 << " ";
        a = NEX[a];
    }

    return 0;
}