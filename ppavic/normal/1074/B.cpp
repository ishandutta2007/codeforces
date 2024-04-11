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

const int N = 1e3 + 50;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, t, k1, k2, comp[N][2], pit = 0, ans = 0;
vi v[N];

int find(int x,int lst){
    if(comp[x][0]) return x;
    int ret = -1;
    for(int y : v[x]){
        if(y != lst)
            ret = max(ret, find(y, x));
    }
    return ret;
}

void solve(){
    for(int i = 0;i<N;i++){
        v[i].clear();
    }
    memset(comp, 0, sizeof(comp));
    scanf("%d", &n);
    for(int i = 1;i<n;i++){
        int x, y;scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d", &k1);
    for(int i = 0;i<k1;i++){
        int x;scanf("%d", &x);
        comp[x][0] = 1;
    }
    scanf("%d", &k2);
    for(int i = 0;i<k2;i++){
        int x;scanf("%d", &x);
        pit = x;
        comp[x][1] = 1;
    }
    printf("B %d\n", pit);
    fflush(stdout);
    scanf("%d", &ans);
    if(comp[ans][0]){
        printf("C %d\n", ans);
    fflush(stdout);

        return;
    }
    int y = find(ans, ans);
    printf("A %d\n", y);
    fflush(stdout);
    scanf("%d", &ans);
    if(comp[ans][1]){
        printf("C %d\n", y);
        fflush(stdout);

        return;
    }
    printf("C -1\n");
    fflush(stdout);
}

int main(){
    int T;scanf("%d", &T);
    for(;T--;) solve();
    return 0;
}