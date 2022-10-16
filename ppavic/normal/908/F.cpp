#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <deque>

#define X first
#define Y second
#define INP(x) scanf("%d",&(x))
#define OUT(x) printf("%d\n",(x))
#define INP2(x,y) scanf("%d%d",&(x),&(y))
#define OUT2(x,y) printf("%d %d\n",(x),(y))
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef vector < int > vi;
typedef pii pt;
typedef pair < ll,ll> pll;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 31337;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

vector < ll > r[2],v;

ll cost[N][2];

int n;

int main(){
    scanf("%d",&n);
    v.PB(-INF);
    for(int i = 0;i<n;i++){
        int x;char c;
        scanf("%d %c",&x,&c);
        if(c == 'G') v.PB(x);
        if(c == 'R') r[0].PB(x);
        if(c == 'B') r[1].PB(x);
    }
    v.PB(INF);
    for(int k = 0;k<2;k++){
        int lo = 0,hi = 0;
        for(int i = 0;i<v.size() - 1;i++){
            if(lo < r[k].size() && r[k][lo] > v[i + 1]) continue;
            while(lo < r[k].size() && r[k][lo] < v[i]) lo++;
            while(hi < r[k].size() && r[k][hi] < v[i + 1]) hi++;
            if(lo == hi) continue;
            ll l = r[k][lo];
            if(i != 0)
                l = v[i];
            ll rr = r[k][hi - 1];
            if(i != v.size() - 2)
                rr = v[i + 1];
            ll odu = max(v[i + 1] - r[k][hi - 1],r[k][lo] - v[i]);
            for(int i = lo;i<hi-1;i++){
                odu = max(odu, r[k][i + 1] - r[k][i]);
            }
            if(v.size() == 2 || i == 0 || i == v.size() - 2)
                odu = 0;
            cost[i][k] = (ll)rr - (ll)l - (ll)odu;
        }
    }
    ll fin = 0;
    for(int i = 0;i<v.size() - 1;i++){
        if(i == 0 || i == v.size() - 2){
            fin += (ll)cost[i][0] + (ll)cost[i][1];
            continue;
        }
        ll sm = cost[i][0] + cost[i][1] + v[i + 1] - v[i];
        fin += min(sm, 2LL * (v[i + 1] - v[i]));
    }
    printf("%I64d\n", fin);
    return 0;
}