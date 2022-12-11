#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 100010
#define PB push_back

using namespace std;

vector<int> near[N];
int arr[N];
int n, m;

long long sum[N];
long long sum_all = 0;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++) {
		scanf("%d", &arr[i]);
		if(i > 0 && arr[i] != arr[i-1]) {
			near[arr[i]].PB(arr[i-1]);
			near[arr[i-1]].PB(arr[i]);
			long long val = abs(arr[i] - arr[i-1]);
			sum_all += val;
			sum[arr[i]] += val;
			sum[arr[i-1]] += val;
		}
	}
	long long ans = sum_all;
	for(int i = 1;i <= n;i++) {
		if(near[i].size() == 0) {
			continue;
		}
		sort(near[i].begin(), near[i].end());
		int mid = near[i][near[i].size()/2];
		long long val = 0;
		for(int j = 0;j < near[i].size();j++) {
			val += abs(near[i][j] - mid);
		}
		if(sum_all - sum[i] + val < ans) {
			ans = sum_all - sum[i] + val;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}