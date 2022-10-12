#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 200000;

int S;

struct Query {
	int l, r;
	int idx;
	
	bool operator < (const Query &other) const {
		if (l / S == other.l / S) return r < other.r;
		return l < other.l;
	} 
	
} query[N];

int cnt[1000001];
int a[N];
pair <int, long long> ans[N];

int main () {

	int n, t;
	scanf ("%d %d", &n, &t);
	for (int i = 0; i < n; i++) scanf ("%d", a + i);
	
	S = (int) sqrt(n);	
	
	for (int i=0; i<t; i++) {
		scanf ("%d %d", &query[i].l, &query[i].r);
		query[i].l--;
		query[i].r--;		
		query[i].idx = i;		
	}
	
	sort (query, query + t);
	
	long long tot = 0;
	int l = 1;
	int r = 0;
	for (int i=0; i<t; i++) {
		while (l < query[i].l) {
			tot -= (long long) a[l] * (2 * cnt[a[l++]]-- - 1);			
		}
		
		while (l > query[i].l) {
			tot += (long long) a[--l] * (2 * cnt[a[l]]++ + 1);			 
		}
		
		while (r < query[i].r) {
			tot += (long long) a[++r] * (2 * cnt[a[r]]++ + 1);			 
		}
		
		while (r > query[i].r) {
			tot -= (long long) a[r] * (2 * cnt[a[r--]]-- - 1);
		}
		
		ans[i] = make_pair (query[i].idx, tot);
	}
	
	sort (ans, ans + t);
	
	for (int i=0; i<t; i++) printf ("%I64d\n", ans[i].second);	
	return 0;
}