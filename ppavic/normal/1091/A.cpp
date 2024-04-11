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

int y, b, r;

int main(){
    scanf("%d%d%d", &y, &b, &r);
    int x = min(min(y, b - 1), r - 2);
    printf("%d\n", max(3 * x + 3, 0));
    return 0;
}