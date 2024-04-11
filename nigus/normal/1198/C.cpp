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

const ll MAXN = 300001;

vector<vl> C(MAXN, vl());

unordered_map<ll,ll> M;

vector<pii> mat;
vi leaves;

bool mark[MAXN] = {0};
bool matched[MAXN] = {0};
ll root = 0;

void dfs(ll i, ll par){
    if(mark[i])return;

    mark[i] = 1;
    int chi = 0;
    rep(c1,0,sz(C[i])){
        int a = C[i][c1];
        if(!mark[a]){
            dfs(a,i);
            chi++;
        }
    }
    if(chi == 0)leaves.push_back(i);

    if(par != -1 && matched[par] == 0 && matched[i] == 0){
        matched[par] = 1;
        matched[i] = 1;
        mat.push_back({i,par});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        n = 3*n;
        rep(c1,0,n){
            C[c1].clear();
            mark[c1] = 0;
            matched[c1] = 0;
        }
        mat.clear();
        leaves.clear();
        M.clear();

        rep(c1,0,m){
            cin >> a >> b;
            a--;b--;
            M[a*MAXN + b] = c1;
            M[b*MAXN + a] = c1;
            C[a].push_back(b);
            C[b].push_back(a);
        }
        rep(c1,0,n){
            if(!mark[c1]){
                dfs(c1,-1);
            }
        }
        if(sz(leaves) >= n/3){
            cout << "IndSet\n";
            rep(c1,0,min(n/3,ll(sz(leaves)))){
                cout << leaves[c1]+1 << " ";
            }cout << "\n";
        }
        else{
            cout << "Matching\n";
            assert(sz(mat) >= n/3);
            rep(c1,0,min(n/3,ll(sz(mat)))){
                //cerr << mat[c1].first << " " << mat[c1].second << "  fsd\n";
                cout << M[mat[c1].first*MAXN + mat[c1].second] + 1 << " ";
            }cout << "\n";
        }
    }

    return 0;
}