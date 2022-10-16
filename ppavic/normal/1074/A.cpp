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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, m, x[N], a1[N], a2[N], b[N], nd[N], sol = INF;
vi v;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<n;i++){
        scanf("%d", x + i);
    }
    for(int i = 0;i<m;i++){
        scanf("%d%d%d", a1 + i, a2 + i, b + i);
        if(a1[i] == 1){
            v.push_back(a2[i]);
        }
    }
    sort(v.begin(), v.end());
    sort(x, x + n);
    x[n] = 1e9;
    int j = 0;
    for(int i = 0;i<=n;i++){
        while(j < v.size() && v[j] < x[i]) j++;
        sol = min(sol, (int)v.size() - j + i);
    }
    printf("%d\n", sol);
    return 0;
}