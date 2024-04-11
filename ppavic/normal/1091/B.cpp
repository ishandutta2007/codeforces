#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>

#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int n, cnt;
map < pii , int > mp;
int x[N], y[N], a[N], b[N];

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d%d", x + i, y + i);
    }
    for(int i = 0;i<n;i++){
        scanf("%d%d", a + i, b + i);
    }
    for(int i = 0;i<n;i++){
        mp.clear();
        for(int i = 0;i<n;i++){
            mp[{a[i], b[i]}]++;
        }
        int tx = x[0] + a[i];
        int ty = y[0] + b[i];
        int bad = 0;
        for(int j = 1;j<n;j++){
            if(mp[{tx - x[j], ty - y[j]}] == 0){
                bad = 1;break;
            }
            mp[{tx - x[j], ty - y[j]}]--;
        }
        if(bad) continue;
        printf("%d %d\n", tx, ty);
        return 0;
    }
    return 0;
}