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

ll n,m,T,k,d;
const ll big = 1000000007;

string cols;
vi R;

ll DP[51][2001] = {0};
bool DPC[51][2001] = {0};

ll dp(int i, int j){
    if(j <= 0)return 0;
    if(DPC[i][j])return DP[i][j];
    ll ans = big;
    for(int c1 = 0; c1 < n; c1++){
        if(R[i] < R[c1] && cols[i] != cols[c1]){
            ans = min(ans, abs(c1-i) + dp(c1,j-R[c1]));
        }
    }
    DPC[i][j] = 1;
    DP[i][j] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n >> a >> k;a--;
    for(int c1 = 0; c1 < n; c1++){
        cin >> b;
        R.push_back(b);
    }
    cin >> cols;
    ll ans = big;
    for(int c1 = 0; c1 < n; c1++){
        ans = min(ans, abs(a-c1) + dp(c1,k-R[c1]));
    }
    if(ans >= big)ans = -1;
    cout << ans << "\n";
    return 0;
}