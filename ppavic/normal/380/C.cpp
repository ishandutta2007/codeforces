#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back
#define TRACE(x) printf("%s = %d\n", #x, x);

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vp;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

char s[M];
int p[M], tour[2 * OFF], n;

int query(int i,int a,int b,int lo,int hi){
    if(lo <= a && b <= hi) return tour[i];
    if(a > hi || b < lo) return INF;
    return min(query(2 * i, a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi));
}

int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 1;i <= n;i++)
        p[i] = p[i - 1] + ((s[i - 1] == '(') ? 1 : -1), tour[i + OFF] = p[i];
    for(int i = OFF - 1; i ; i--)
        tour[i] = min(tour[2 * i], tour[2 * i + 1]);
    int q; scanf("%d", &q);
    for(int i = 0;i < q;i++){
        int l, r; scanf("%d%d", &l, &r);
        int poc = p[l - 1];
        int mi = query(1, 0, OFF - 1, l - 1, r);
        int kraj = p[r];
        //printf("LR [%d %d] POC : %d KRAJ : %d MIN : %d\n", l, r, poc, kraj, mi);
        printf("%d\n", (r - l + 1) - abs((kraj + (poc - mi)) - poc) - abs(poc - mi));

    }
    return 0;
}