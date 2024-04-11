#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef pair < ll, ll > pll;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

int n, k;

void solve(){
	scanf("%d%d", &n, &k);
	vi sol;
	for(int i = 1;i <= n;i++)
		if(2 * i >= k && i != k) 
			sol.PB(i);
	printf("%d\n", (int)sol.size());
	for(int x : sol)
		printf("%d ", x);
	printf("\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}