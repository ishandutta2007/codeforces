#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << LOG);

int n;
ll a[N];

int main(){
	scanf("%d", &n);
	if(n == 1){
		int x; scanf("%d", &x);
		printf("1 1\n%d\n", -x);
		printf("1 1\n%d\n", 0);
		printf("1 1\n%d\n", 0);
		return 0;
	}
	for(int i = 0;i < n;i++)
		scanf("%lld", a + i);
	printf("1 %d\n", n);
	for(int i = 0;i < n;i++){
		ll md = (a[i] % (n - 1));
		if(md <= 0) md += n - 1;
		printf("%lld ", (ll)(n - 1 - md) * n);
		a[i] += (ll)(n - 1 - md) * n;
	}
	printf("\n1 1\n");
	printf("%lld\n", -a[0]);
	printf("2 %d\n", n);
	for(int i = 1;i < n;i++)
		printf("%lld ", -a[i]);
	printf("\n");
	return 0;
}