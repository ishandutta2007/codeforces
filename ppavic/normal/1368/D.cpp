#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 2e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);

int A[25][N], n;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		for(int j = 0;j < 20;j++)
			A[j][i] = (x & (1 << j));
	}
	for(int j = 0;j < 20;j++)
		sort(A[j], A[j] + n);
	ll sol = 0;
	for(int i = 0;i < n;i++){
		ll cur = 0;
		for(int j = 0;j < 20;j++)
			cur += A[j][i];
		sol += cur * cur;
	}
	printf("%lld\n", sol);
	return 0;
}