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
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return DD(eng)%r;
}

const ll big = 1000000007;

ll n,m,T,k,q;
const int MAXN = 5000;
vl A;

bool DPC[MAXN+2][MAXN+2] = {0};
int DP[MAXN+2][MAXN+2] = {0};

int dp(int i, int j){
    if(i ==-1 && j == n)return 0;
    if(DPC[i+1][j+1])return DP[i+1][j+1];
    int ans = big;
    if(i > -1){
        ans = min(ans,1 + dp(i-1,j));
    }
    if(j < n){
        ans = min(ans,1 + dp(i,j+1));
    }
    if(i > -1 && j < n && A[i] == A[j]){
        ans = min(ans, 1 + dp(i-1,j+1));
    }
    DPC[i+1][j+1] = 1;
    DP[i+1][j+1] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n;
    ll prev = -1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;a--;
        if(a != prev)A.push_back(a);
        prev = a;
    }
    n = sz(A);
    int ans = big;
    for(int c1 = 0; c1 < n; c1++){
        ans = min(ans, dp(c1-1,c1+1));
    }
    cout << ans << "\n";

    return 0;
}