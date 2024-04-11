#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 3e5 + 50;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

set < pii > s;
int x[N], y[N], n, a, b, c, d;
ll dp[N][4][4][4];

int dis(int i,int j){
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

ll f(int i,int k,int k1, int k2){
    if(k1 > 3 || k2 > 3) return -2 * INF;
    if(k == 3 && k1 == 3 && k2 == 3) return 0;
    if(i == n || k == 3) return -2 * INF;
    if(dp[i][k][k1][k2] != -1) return dp[i][k][k1][k2];
    ll ret = f(i + 1, k, k1, k2);
    ret = max(ret, f(i + 1, k + 1, k1, k2) - 2 * x[i] - 2 * y[i]);
    ret = max(ret, f(i + 1, k + 1, k1, k2 + 1) - 2 * x[i]);
    ret = max(ret, f(i + 1, k + 1, k1, k2 + 2) - 2 * x[i] + 2 * y[i]);
    ret = max(ret, f(i + 1, k + 1, k1 + 1, k2) - 2 * y[i]);
    ret = max(ret, f(i + 1, k + 1, k1 + 1, k2 + 1));
    ret = max(ret, f(i + 1, k + 1, k1 + 1, k2 + 2) + 2 * y[i]);
    ret = max(ret, f(i + 1, k + 1, k1 + 2, k2) + 2 * x[i] - 2 * y[i]);
    ret = max(ret, f(i + 1, k + 1, k1 + 2, k2 + 1) + 2 * x[i]);
    ret = max(ret, f(i + 1, k + 1, k1 + 2, k2 + 2) + 2 * x[i] + 2 * y[i]);
    return dp[i][k][k1][k2] = ret;
}

int brute(){
    int sol = 0;
    for(int i = 0;i<n;i++){
        for(int j = i + 1;j<n;j++){
            for(int k = j + 1;k<n;k++){

                sol = max(sol, dis(i, j) + dis(j, k) + dis(i, k));
            }
        }
    }
    return sol;
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    a = 0, b = 0, c = 0, d = 0;
    for(int i = 0;i<n;i++){
        scanf("%d%d", x + i, y + i);
        if(x[i] <= x[a]) a = i;
        if(x[i] >= x[b]) b = i;
        if(y[i] <= y[c]) c = i;
        if(y[i] >= y[d]) d = i;
    }
    printf("%d\n", f(0,0,0,0));
    for(int i = 4;i<=n;i++){
        printf("%d\n", 2 * ((x[b] - x[a]) + (y[d] - y[c])));
    }

}