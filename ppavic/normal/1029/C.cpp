#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long lll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < lll, lll > pll;
typedef vector < int > vi;
typedef vector < lll > vl;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const lll INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, l[N], r[N], ll[N], rr[N];
vector < pii > v;
set < int > s;

int main(){
    scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        scanf("%d%d", l + i, r + i);
        v.PB({l[i], -i});
        v.PB({r[i], i});
        ll[i] = INF;
        rr[i] = -INF;
        s.insert(i);
    }
    ll[0] = INF;rr[0] = -INF;
    sort(v.begin(), v.end());
    for(int i = 0;i<2 * n;i++){
        if(s.size() == 1){
            int x = *s.begin();
            rr[x] = max(rr[x], v[i].X);
        }
        if(s.size() == 0){
            rr[0] = max(rr[0], v[i].X);
        }
        if(v[i].Y > 0){
            s.insert(v[i].Y);
        }
        else{
            s.erase(-v[i].Y);
        }
        if(s.size() == 1){
            int x = *s.begin();
            ll[x] = min(ll[x], v[i].X);
        }
        if(s.size() == 0){
            ll[0] = min(ll[0], v[i].X);
        }
    }
    int sol = 0;
    for(int i = 0;i<=n;i++){
        rr[i] = max(rr[i], rr[0]);
        ll[i] = min(ll[i], ll[0]);
        sol = max(sol, rr[i] - ll[i]);
    }
    printf("%d\n", sol);

}