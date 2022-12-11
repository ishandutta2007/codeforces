#include <iostream>
#include <map>

#define N 30
#define L (20ll)

using namespace std;

map<long long, long long> dp[N];

long long fac[N];
long long a[N];
int n, k;
long long S, ans = 0;
int l1, l2;

void dfs1(int idx, int use, long long sum) {
	if(use > k || sum > S) {
		return;
	}
	if(idx >= l1) {
		dp[use][sum]++;
		return;
	}
	if(a[idx] < L) {
		dfs1(idx+1, use+1, sum + fac[a[idx]]);
	}
	dfs1(idx+1, use, sum + a[idx]);
	dfs1(idx+1, use, sum);
}
void dfs2(int idx, int use, long long sum) {
	if(use > k || sum > S) {
		return;
	}
	if(idx <= l2) {
		for(int i = use;i <= k;i++) {
			if(dp[i-use].find(S-sum) != dp[i-use].end()) {
				ans += dp[i-use][S-sum];
			}
		}
		return;
	}
	if(a[idx] < L) {
		dfs2(idx-1, use+1, sum + fac[a[idx]]);
	}
	dfs2(idx-1, use, sum + a[idx]);
	dfs2(idx-1, use, sum);
}
int main() {
	fac[0] = 1;
	for(long long i = 1ll;i < L;i++) {
		fac[i] = fac[i-1] * i;
	}
	cin >> n >> k >> S;
	l1 = n/2;
	l2 = l1-1;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	dfs1(0, 0, 0ll);
	dfs2(n-1, 0, 0ll);
	cout << ans << endl;
	return 0;
}