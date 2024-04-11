#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int MAXN = 100010;

int n;
int par[MAXN];
vector<int> flips;
int dn[2];
vector<int> E[MAXN];
int a[MAXN], b[MAXN];

void dfs(int u, int h){
    bool bb = 0;
    if(a[u] ^ b[u] ^ dn[h&1]){
        bb = 1;
        flips.push_back(u);
        dn[h&1] ^= 1;
    }
    for(int v : E[u]){
        if(v == par[u]) continue;
        par[v] = u;
        dfs(v, h+1);
    }
    if(bb)
        dn[h&1] ^= 1;
}

int main(){
    scanf("%d", &n);
    FWD(i,0,n-1){
        int c, d;
        scanf("%d %d", &c, &d);
        E[c].push_back(d);
        E[d].push_back(c);
    }
    FWD(i,1,n+1) scanf("%d", &a[i]);
    FWD(i,1,n+1) scanf("%d", &b[i]);
    dfs(1, 0);
    printf("%d\n", (int)flips.size());
    for(int u : flips) printf("%d\n", u);
    return 0;
}