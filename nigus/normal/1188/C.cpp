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

const ll MAXN = 1001;

vi A;

bool diffs[100001] = {0};

bool check(int diff){
    int now = 0;
    int done = 1;
    rep(c1,1,n){
        if(A[c1]-A[now] >= diff){
            done++;
            now = c1;
        }
        if(done >= k)return 1;
    }
    return (done >= k);
}

int NEX[MAXN] = {0};

void fix(ll diff){
    int prev = 0;
    rep(c1,0,n){
        NEX[c1] = n;
        rep(c2,max(c1+1,prev),n){
            if(A[c2] - A[c1] >= diff){
                NEX[c1] = c2;
                break;
            }
        }
        prev = NEX[c1];
    }
}


int DP[MAXN][MAXN] = {0};

/*
ll dp(ll i, ll j, bool found, bool skip, ll diff){
    if(i == n)return (found && (j == 0));
    if(j < 0)return 0;
    if(DPC[i][j][found][skip] == diff)return DP[i][j][found][skip];
    ll nex = NEX[i];
    ll ans = 0;

    if(skip){
        ans = dp(i+1,j,found,1,diff);
        if(i+1 != n){
            ans += dp(i+1,j-1,found,0,diff);
        }
        ans %= mod;
        DPC[i][j][found][skip] = diff;
        DP[i][j][found][skip] = ans;
        return ans;
    }

    if(nex == n){
        ans = dp(nex,j,found,1,diff);
    }
    else{
        if(A[nex] - A[i] == diff){
            ans += dp(nex,j-1,1,0,diff);
        }
        else{
            ans += dp(nex,j-1,found,0,diff);
        }
        ans += dp(nex,j,found,1,diff);
        ans %= mod;
    }

    DPC[i][j][found][skip] = diff;
    DP[i][j][found][skip] = ans;
    return ans;
}
*/

void dp2(int diff){
    for(int i2 = 0; i2 <= n; i2++){
        for(int j = 0; j <= k; j++){
            int i = n-i2;
            if(i == n){
                DP[i][j] = (j == 0);
            }
            else{
                DP[i][j] = DP[i+1][j];
                if(j != 0)DP[i][j] += DP[NEX[i]][j-1];
                if(DP[i][j] >= mod)DP[i][j] -= mod;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n >> k;

    /*
    rep(c1,0,4123){
        rand();
    }
*/
    rep(c1,0,n){
        cin >> a;
        //a = rand()%100001;

        A.push_back(a);
    }
    sort(all(A));
    A.push_back(-1337);

    rep(c1,0,n){
        rep(c2,0,n){
            diffs[abs(A[c1] - A[c2])] = 1;
        }
    }

    ll ans = 0;
    rep(c1,1,100001 / (k-1) + 2){
       // if(!diffs[c1])continue;
        if(!check(c1))break;
            fix(c1);
           // cerr << c1 << " " << ans<< "   " << check(c1) << "\n";
/*
            ans += dp(0,k,0,1,c1) * ll(c1);
            ans += dp(0,k-1,0,0,c1) * ll(c1);
            ans %= mod;
*/

            dp2(c1);
            ans += ll(DP[0][k]);
            ans %= mod;


    }

    cout << ans << "\n";

    return 0;
}