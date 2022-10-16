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

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);

int n;

int main(){
	scanf("%d", &n);
	printf("%d\n", 3 * n + 4);
	for(int i = 0;i < n + 2;i++)
		printf("%d %d\n", i, i);
	for(int i = 0;i < n + 1;i++)
		printf("%d %d\n", i, i + 1);
	for(int i = 0;i < n + 1;i++)
		printf("%d %d\n", i + 1, i);
	return 0;
}