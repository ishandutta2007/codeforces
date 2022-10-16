#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define TRACE(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 20);
const double EPS = 1e-9;
const double PI = 3.1415926535;

vector < pair < int, pii > > vpi;
int x1[N], x2[N], yy1[N], y2[N], tour[2 * OFF + 500], prop[2 * OFF + 500], n;
vi saz;

void sazimanje(){
    for(int i = 0;i<n;i++){
        saz.PB(x1[i]);saz.PB(x2[i]);
        saz.PB(yy1[i]);saz.PB(y2[i]);
    }
    sort(saz.begin(), saz.end());
    saz.erase(unique(saz.begin(), saz.end()), saz.end());
    for(int i = 0;i<n;i++){
        yy1[i] = lower_bound(saz.begin(), saz.end(), yy1[i]) - saz.begin() + 1;
        y2[i] = lower_bound(saz.begin(), saz.end(), y2[i]) - saz.begin() + 1;
    }
}

void refresh(int x){
    if(!prop[x]) return;
    tour[x] += prop[x];
    if(x < OFF){
        prop[2 * x] += prop[x];
        prop[2 * x + 1] += prop[x];
    }
    prop[x] = 0;
}

void update(int i,int a,int b,int lo, int hi, int x){
    refresh(i);
    if(lo <= a && b <= hi){
        prop[i] += x;
        refresh(i);
        return;
    }
    if(a > hi || b <lo) return;
    update(2 * i, a, (a + b) / 2, lo, hi, x);
    update(2 * i + 1, (a + b + 2) / 2, b, lo, hi, x);
    tour[i] = max(tour[2 * i], tour[2 * i + 1]);
}

int query(int i,int a,int b,int lo,int hi){
    refresh(i);
    if(lo <= a && b <= hi) return tour[i];
    if(a > hi || b < lo) return 0;
    return max(query(2 * i, a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b + 2) / 2, b, lo, hi));
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d%d%d%d", x1 + i, yy1 + i, x2 + i, y2 + i);
    }
    sazimanje();
    for(int i = 0;i<n;i++){
        vpi.PB({x1[i], {-yy1[i], y2[i]}});
        vpi.PB({x2[i], {yy1[i], y2[i]}});
    }
    sort(vpi.begin(), vpi.end());
    for(int i = 0;i<2 * n;i++){
        if(vpi[i].Y.X < 0){
            vpi[i].Y.X *= -1;
            update(1, 0, OFF - 1, vpi[i].Y.X, vpi[i].Y.Y, 1);
        }
        else{
            update(1, 0, OFF - 1, vpi[i].Y.X, vpi[i].Y.Y, -1);
        }
        if(query(1, 0, OFF - 1, 0, OFF - 1) >= n - 1){
            for(int j = 0;j < OFF;j++){
                if(query(1, 0, OFF - 1,j,j) >= n - 1){
                    printf("%d %d\n", vpi[i].X, saz[j - 1]);
                    return 0;
                }
            }
        }
    }
    return 0;
}