#include <cstdio>
#include <cstring>
#include <cstdlib>
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
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << 20);

int n, k;

void solve(){
	scanf("%d%d", &n, &k);
	if(k == n - 1 && k == 3){
		printf("-1\n");
		return;
	}
	if(k == n - 1){
		vector < int > l, r; int ln = __builtin_popcount(n - 1);
		for(int i = 0;i < n;i += 2){
			if(__builtin_popcount(i) == 1 || __builtin_popcount(i) == ln - 1) continue;
			printf("%d %d\n", i, n - i - 1);
		}	
		for(int i = 1;i < n;i *= 2)
			l.PB(i), r.PB(n - i - 1);
		for(int i = 0;i < (int)l.size();i++)
			printf("%d %d\n", l[i], r[(i + 1) % (int)l.size()]);
		return;
	}
	if(k == 0){
		for(int i = 0;i < n;i += 2)
			printf("%d %d\n", i, n - i - 1);
		return;
	}
	printf("%d %d\n", k, n - 1);
	printf("%d %d\n", 0, n - k - 1);
	for(int i = 1;i + 1 < n;i += 2){
		if(i == k || i == n - k - 1) continue;
		printf("%d %d\n", i, n - i - 1);
	}
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}