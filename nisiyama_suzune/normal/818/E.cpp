#include <bits/stdc++.h>

int size;
int fact[20], fact_s[20];

struct array {
	int d[15];
	array () {
		for (int i = 0; i < 15; ++i) d[i] = 0;
	}
};

array pre[110000];
int N, K;

int lower_bound (const array &a) {
	int l = 0, r = N, ans = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		bool f = true;
		for (int i = 0; i < size; ++i)
			if (pre[m].d[i] < a.d[i]) {
				f = false;
				break;
			}
		if (f) {
			ans = m;
			r = m - 1;
		} else
			l = m + 1;
	}
	return ans;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	std::cin >> N >> K;
	for (int i = 2; 1LL * i * i <= K; ++i) {
		if (K % i == 0) {
			fact[size] = i;
			while (K % i == 0) {
				++fact_s[size];
				K /= i;
			}
			++size;
		}
	}
	if (K > 1) {
		fact[size] = K;
		fact_s[size++] = 1;
	}
	for (int i = 1; i <= N; ++i) {
		int A;
		std::cin >> A;
		for (int j = 0; j < size; ++j) 
			while (A % fact[j] == 0) {
				++pre[i].d[j];
				A /= fact[j];
			}
	}
	for (int i = 1; i <= N; ++i) 
		for (int j = 0; j < size; ++j)
			pre[i].d[j] += pre[i - 1].d[j];
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		array demand = pre[i];
		for (int j = 0; j < size; ++j)
			demand.d[j] += fact_s[j];
		int m = lower_bound (demand);
		if (m == -1) continue;
		ans += std::min (N - m + 1, N - i);
	}
	std::cout << ans << std::endl;
}