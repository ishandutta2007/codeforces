#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define PB push_back
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

set < int > s;
int n, q, l[N], r[N], a[N], dod[N], b[N], uz[N];

int main(){
    memset(l, INF, sizeof(l));
    memset(r, -1, sizeof(r));
    scanf("%d%d", &n, &q);
    b[n] = 1;
    for(int i = 0;i<n;i++){
        scanf("%d", a + i);
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    if(l[q] == INF){
        int naso = 0;
        for(int i = 0;i<n;i++){
            if(a[i] == 0){
                a[i] = q;
                l[q] = i;
                r[q] = i;
                naso = 1;
                break;
            }
        }
        if(!naso){
            printf("NO\n");
            return 0;
        }
    }
    for(int i = 1;i<=q;i++){
        if(l[i] == INF) continue;
        dod[l[i]] = i;
        uz[r[i] + 1] = i;
    }
    for(int i = 0;i<n;i++){
        if(dod[i] > 0) s.insert(dod[i]);
        if(uz[i] > 0) s.erase(uz[i]);
        if(a[i] && s.size() > 0 && a[i] != *s.rbegin()){
            printf("NO\n");
            return 0;
        }
        if(s.empty()) continue;
        b[i] = *s.rbegin();
    }
    for(int i = n-1;i>=0;i--){
        if(!b[i]) b[i] = b[i + 1];
    }
    printf("YES\n");
    for(int i = 0;i<n;i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}