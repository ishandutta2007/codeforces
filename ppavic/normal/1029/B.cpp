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

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);
const int BASE = 31337;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, dp[N], j = 0, a[N], sol, tour[2 * OFF + 500];

void update(int i,int x){
    tour[OFF + i] = x;
    i += OFF;
    for(i = i / 2; i ; i /= 2)
        tour[i] = max(tour[2 * i], tour[2 * i + 1]);
}

int query(int i,int a,int b,int lo,int hi){
    if(lo <= a && b <= hi) return tour[i];
    if(a > hi || b < lo) return 0;
    return max(query(2 * i , a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b + 2) / 2, b, lo, hi));
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        scanf("%d", a + i);
        while(j < i && 2 * a[j] < a[i]) j++;
        dp[i] = query(1, 0, OFF - 1, j, i) + 1;
        update(i, dp[i]);
        sol = max(sol, dp[i]);
    }
    printf("%d\n", sol);
    return 0;
}