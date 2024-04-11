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

const ll N = 1e6 + 500;
const ll M = 1e6 + 500;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const double PI = 3.1415926535;
const double EPS = 1e-9;

ll dp[N], x[N], y[N], p[N], n, a[N];
ll sol = 0;
vector < pii > v;
vector < pii > env;

bool cmp(ll i,ll j){
    return x[i] < x[j];
}

inline ld ccw(pii A,pii B,pii C){
    return (ld)A.X * (B.Y - C.Y) + (ld)B.X * (C.Y - A.Y) + (ld)C.X * (A.Y - B.Y);
}

inline ll get(ll x,ll y,ll i){
    if(i >= env.size() || i < 0) return -(ll)INF * INF;
    return env[i].X * x + env[i].Y * y;
}

ll query(ll lo,ll hi,ll x,ll y){
    while(lo < hi){
        ll mid = (lo + hi) >> 1;
        if(get(x, y, mid) > get(x, y, mid + 1))
            hi = mid;
        else
            lo = mid + 1;
    }
    ll ret = -(ll)INF * INF;
   ret = max(ret, get(x, y, lo));
    return ret;
}

void add(pii A){
    while(env.size() >= 2 && ccw(env[env.size() - 2],env.back(), A) < 0){
        env.pop_back();
    }
    env.push_back(A);
}

int main(){
    scanf("%d", &n);
    for(ll i = 0;i<n;i++){
        scanf("%lld%lld%lld", x + i, y + i, a + i);p[i] = i;
    }
    sort(p, p + n, cmp);
    for(ll k = 0;k<n;k++){
        ll i = p[k];
        dp[i] = (ll)x[i] * y[i] - a[i];
        if(k != 0){
            dp[i] = max(query(0, env.size() - 1, y[i], 1) + x[i] * y[i] - a[i], dp[i]);
        }
        sol = max(sol,(ll) dp[i]);
        add({-x[i], dp[i]});
    }
    printf("%lld\n", sol);
    return 0;
}