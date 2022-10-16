#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef pair < pii, int > ppi;
typedef pair < int, pii > pip;
typedef long double ld;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);
const int MOD =  998244353;
const ld PI = 3.1415926535;
const ld EPS = 1e-9;

int h, w;

int main(){
	scanf("%d%d", &h, &w);
	int ans = 2;
	for(int i = 0;i < h + w - 1;i++)
		ans = 2 * ans % MOD;
	printf("%d\n", ans);
	return 0;
}