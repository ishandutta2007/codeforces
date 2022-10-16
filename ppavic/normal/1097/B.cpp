#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;

int a[N], n;

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d", a + i);
    }

    for(int i = 0;i<(1 << n);i++){
        int sum = 0;
        for(int j = 0;j<n;j++){
            if((1 << j) & i) sum += a[j];
            else sum -= a[j];
        }
        if(sum % 360 == 0){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}