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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << 20);

int n, k, A[N], cnt[N];

void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) cnt[i] = 0;
	for(int i = 0;i < n;i++)
		scanf("%d", A + i), cnt[A[i]]++;
	int bar = (n + k + 1) / 2, j = 0;
	int x = 1, y = n;
	int csum = 0;
	for(int i = 1;i <= n;i++){
		while(j <= n && csum < bar) csum += cnt[++j];
		if(j > n) break;
		if(j - i < y - x) x = i, y = j;
		csum -= cnt[i];
	}
	printf("%d %d\n", x, y);
	int lst = 0, trz = 1;
	for(int i = 0;i < n && trz < k;i++){
		A[i] = (i ? A[i - 1] : 0) + (x <= A[i] && A[i] <= y ? 1 : -1);
		if(A[i] == trz){
			printf("%d %d\n", lst + 1, i + 1);
			lst = i + 1; trz++;
		}
	}
	printf("%d %d\n", lst + 1, n);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}