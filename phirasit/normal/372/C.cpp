#include <stdio.h>
#include <deque>

#define N 150010

using namespace std;

deque<int> deq;

long long tmp[N];
long long dp[N];
int n, m, d;

long long abs(long long x) {
	return x < 0 ? -x : x;
}
int main() {
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1;i <= n;i++) {
		dp[i] = 0;
	}
	int lt = 1;
	for(int c = 0;c < m;c++) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		
		long long df = (long long) (t - lt) * d;

		deq.clear();
		for(int i = 1;i <= n;i++) {
			while(!deq.empty() && i-deq.front() > df) {
				deq.pop_front();
			}
			while(!deq.empty() && dp[i] >= dp[deq.back()]) {
				deq.pop_back();
			}
			deq.push_back(i);
			tmp[i] = dp[deq.front()];
		}
		deq.clear();
		for(int i = n;i >= 1;i--) {
			while(!deq.empty() && deq.front()-i > df) {
				deq.pop_front();
			}
			while(!deq.empty() && dp[i] >= dp[deq.back()]) {
				deq.pop_back();
			}
			deq.push_back(i);
			tmp[i] = max(tmp[i], dp[deq.front()]);
		}
		for(int i = 1;i <= n;i++) {
			dp[i] = tmp[i] + (long long) b - abs(a - i);
		}
		lt = t;
	}
	long long ans = dp[1];
	for(int i = 2;i <= n;i++) {
		if(dp[i] > ans) {
			ans = dp[i];
		}
	}
	printf("%I64d\n", ans);
	return 0;
}