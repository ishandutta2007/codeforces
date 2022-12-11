#include <stdio.h>
#include <deque>

#define N 100010
#define A first
#define B second

using namespace std;

typedef pair<int, int> PII;

deque<PII> mx_deq, mn_deq;

int arr[N], dp[N];
int n, s, l;

int main() {
	scanf("%d%d%d", &n, &s, &l);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	int ls = 1;
	dp[0] = 0;
	for(int i = 1;i <= n;i++) {
		while(!mx_deq.empty() && arr[i] >= mx_deq.back().A) {
			mx_deq.pop_back();
		}
		while(!mn_deq.empty() && arr[i] <= mn_deq.back().A) {
			mn_deq.pop_back();
		}
		mx_deq.push_back(PII(arr[i], i));
		mn_deq.push_back(PII(arr[i], i));
		while(ls < i && (dp[ls-1] == -1 || mx_deq.front().A - mn_deq.front().A > s)) {
			ls++;
			while(mx_deq.front().B < ls) {
				mx_deq.pop_front();
			}
			while(mn_deq.front().B < ls) {
				mn_deq.pop_front();
			}
		}
		if(i-ls+1 < l || dp[ls-1] == -1) {
			dp[i] = -1;
		}else {
			dp[i] = dp[ls-1] + 1;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}