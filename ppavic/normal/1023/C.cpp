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

int dos[N], k, a[N], n;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0;i<n;i++){
        char c;scanf(" %c", &c);
        if(c == ')') a[i] = 1;
    }
    for(int i = n - 1;i>=0;i--) dos[i] = dos[i + 1] + a[i];
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(!k) break;
        if(a[i] && cnt) {
            cnt--;k--;
            printf(")");
        }
        else if(!a[i] && dos[i] > cnt && cnt <= k - 1){
            cnt++;k--;
            printf("(");
        }
    }
    printf("\n");
    return 0;
}