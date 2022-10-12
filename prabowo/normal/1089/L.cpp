#include <bits/stdc++.h>
using namespace std;

int n, k;
int job[100005], num[100005];
pair<int, int> arr[100005];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &job[i]), --job[i], ++num[job[i]];
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i].first), arr[i].second = i;
	sort(arr, arr + n);
	int need = 0;
	for (int i = 0; i < k; ++i) {
		if (num[i]) continue;
		++need;
	}
	long long ans = 0;
	for (int i = 0; i < n && need; ++i) {
		if (num[job[arr[i].second]] <= 1) continue;
		--num[job[arr[i].second]];
		ans += arr[i].first;
		--need;
	}

	printf("%lld\n", ans);
}