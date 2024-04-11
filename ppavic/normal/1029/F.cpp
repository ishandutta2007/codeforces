#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const ll INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll a, b;

vector < pll > va, vb;

int main(){
    cin >> a >> b;
    ll P = a + b;
    for(ll x = 1;x * x<=a;x++){
        if(a % x) continue;
        va.PB({ x, a / x});
    }
    for(ll x = 1;x * x<=b;x++){
        if(b % x) continue;
        vb.PB({ x, b / x});
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    ll sol = INF * INF;
    for(ll x = 1;x * x <= P;x++){
        if(P % x) continue;
        ll y1 = va[upper_bound(va.begin(), va.end(), (pll){x, (ll)INF * INF}) - va.begin() - 1].Y;
        ll y2 = vb[upper_bound(vb.begin(), vb.end(), (pll){x, (ll)INF * INF}) - vb.begin() - 1].Y;
        if(y1 <= P / x || y2 <= P / x){
            sol = min(sol, x  + P / x);
        }
    }
    printf("%lld\n", 2LL  *sol);

}