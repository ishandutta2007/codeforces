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
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

int n, cnt[35];

void solve(){
	scanf("%d", &n); memset(cnt, 0, sizeof(cnt));
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		for(int j = 0;j < 30;j++)
			cnt[j] += !!(x & (1 << j));
	}
	int ans = 0;
	for(int i = 0;i < 30;i++) ans = __gcd(ans, cnt[i]);
	for(int i = 1;i <= n;i++){
		if(ans % i == 0) printf("%d ", i);
	}
	printf("\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}