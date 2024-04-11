#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, s[N], a[N], ans = 0;
ll sum = 0;
vi v[N];

void dfs(int x,int dep, int lst){
    if(dep&1){
        if(s[x] != -1) ans = 1;
        int mi = INF;
        for(int y : v[x]){
            mi = min(mi, s[y]);
        }
        if(mi == INF){
            a[x] = 0;
            s[x] = s[lst];
        }
        else{
            a[x] = mi - s[lst];
            s[x] = s[lst] + a[x];
        }
    }
    else{
        a[x] = s[x] - s[lst];
    }
    if(a[x] < 0) ans = 1;
    sum += (ll)a[x];
    for(int y : v[x]){
        dfs(y, dep + 1, x);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 2;i<=n;i++){
        int x;scanf("%d", &x);
        v[x].PB(i);
    }
    for(int i = 1;i<=n;i++)
        scanf("%d", s + i);
    dfs(1, 0, 0);
    if(ans == 1) printf("-1\n");
    else printf("%lld\n", sum);
    return 0;
}