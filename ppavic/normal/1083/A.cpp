#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <string>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < ll, ll > pii;
typedef vector < ll > vi;
typedef set < ll > si;
typedef vector < pii > vpi;

const ll N = 5e5 + 500;
const ll M = 1e6 + 500;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const double PI = 3.1415926535;
const double EPS = 1e-9;

ll dp[N], w[N], dp2[N], pr[N], mx[N];
ll sol = 0LL;
int n;

vpi v[N];

void calc(ll x,ll lst){
    ll ans = w[x];
    vector < pair < ll, ll > > vv;
    for(pii nxt : v[x]){
        if(nxt.X == lst) continue;
        calc(nxt.X, x);
        ans = max(ans, w[x] + dp[nxt.X] - nxt.Y);
        vv.PB({dp[nxt.X] - nxt.Y + w[x], nxt.X});
    }
    dp[x] = ans;
    sol = max(sol, dp[x]);
    if(vv.size() == 0) return;
    sort(vv.rbegin(), vv.rend());
    for(pii nxt : v[x]){
        if(nxt.X == lst) continue;
        if(nxt.X != vv[0].Y)
            mx[nxt.X] = vv[0].X - nxt.Y + w[nxt.X];
        if(vv.size() > 1 && nxt.X == vv[0].Y){
            mx[nxt.X] = vv[1].X - nxt.Y + w[nxt.X];
        }
    }
}

void calc2(int x, int lst){
    mx[x] = max(mx[x], w[x]);
    for(pii nxt : v[x]){
        if(nxt.X == lst) continue;
        mx[nxt.X] = max(mx[nxt.X], mx[x] - nxt.Y + w[nxt.X]);
        calc2(nxt.X, x);
    }
    sol = max(sol, mx[x]);
}

int main(){
    scanf("%d", &n);
    for(ll i = 1;i<=n;i++) scanf("%lld", w + i);
    for(ll i = 1;i<n;i++){
        int u,vvv,c;scanf("%d%d%d", &u, &vvv, &c);
        v[u].PB({vvv, c});
        v[vvv].PB({u, c});
    }
    calc(n, n);
    calc2(n, n);
    printf("%I64d\n", sol);
    return 0;
}