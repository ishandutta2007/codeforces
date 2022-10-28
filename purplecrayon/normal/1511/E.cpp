//#define DEBUG
#ifndef DEBUG
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define f first
#define s second
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0R(i, x) FOR(i, 0, x)
#define FORd(i, a, b) for(int i = (b)-1; i >= (a); i--)
#define F0Rd(i, x) FORd(i, 0, x)
#define ckif(a, b, c) ((c) ? (a) : (b))
const int MAX_N = 300005;
const ll MOD = 998244353;
const ll INF = 1e18;

ll add(ll a, ll b){ return (a+b)%MOD; }
ll sub(ll a, ll b){ return (a-b+MOD)%MOD; }
ll mul(ll a, ll b){ return (a*b)%MOD; }
ll ADD(ll &a, ll b){ return a=add(a, b); }
ll SUB(ll &a, ll b){ return a=sub(a, b); }
ll MUL(ll &a, ll b){ return a=mul(a, b); }
ll po(ll a, ll b = MOD-2){ return ckif(ckif(mul(a, po(a, b-1)), po(mul(a, a), b/2), b&1), 1, b); }

int n, m;
int dp[MAX_N];
vector<vector<int>> grid;

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    dp[0] = 1;
    FOR(i, 1, MAX_N) dp[i] = add(po(2), mul(sub(1, dp[i-1]), po(2)));
    grid.resize(n);
    F0R(i, n) grid[i].resize(m);
    ll tot = 0;
    F0R(i, n) F0R(j, m){
        char x; cin >> x;
        if(x == 'o') grid[i][j] = 1, tot++;
    }
    ll ans = 0;
    F0R(i, n){
        int num = 0;
        F0R(j, m){
            if(!grid[i][j]){
                num = 0;
                continue;
            }
            num++;
            if(num == 1) continue;
            ADD(ans, dp[num-2]);
        }
    }
    F0R(j, m){
        int num = 0;
        F0R(i, n){
            if(!grid[i][j]){
                num = 0;
                continue;
            }
            num++;
            if(num == 1) continue;
            ADD(ans, dp[num-2]);
        }
    }
    if (tot < 2) { cout << 0 << '\n'; return 0; }
    cout << mul(ans, po(2, tot-2)) << endl;
    return 0;
}