#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define M (2000)

struct Block
{
	int count;
	vector<int> count_val_mod_M;
	int min_delta;
	int max_delta;
	vector<int> count_delta;
	vector<long long> sum_delta;
	vector<int> a;

	Block() {
		count = 0;
		count_val_mod_M = vector<int>(M);
		min_delta = numeric_limits<int>::max();
		min_delta = numeric_limits<int>::max();
		count_delta = vector<int>(M * 4);
		sum_delta = vector<long long>(M * 4);
		a = vector<int>(M);
	}

	int get_count_delta(int delta) const {
		if (count == 0 || delta < min_delta) {
			return 0;
		}
		return count_delta[min(delta, max_delta) - min_delta];
	}

	long long get_sum_of_diff(int delta) const {
		if (count == 0) {
			return 0;
		}
		long long results = 0;
		if (delta < min_delta) {
			results += (long long)(min_delta - delta) * count;
			delta = min_delta;
		}
		if (delta > max_delta) {
			results += (long long)(delta - max_delta) * count;
			delta = max_delta;
		}
		results += (long long)delta * count_delta[delta - min_delta] - sum_delta[delta - min_delta];
		if (delta < max_delta) {
			results += sum_delta[max_delta - min_delta] - sum_delta[delta - min_delta]
				- (long long)delta * (count - count_delta[delta - min_delta]);
		}
		return results;
	}

	void add(int val) {
		++count;
		for (int i = val % M; i < M; ++i) {
			++count_val_mod_M[i];
		}
		int i = count - 1;
		for (; i > 0 && a[i - 1] > val; --i) a[i] = a[i - 1];
		a[i] = val;
		min_delta = numeric_limits<int>::max();
		max_delta = numeric_limits<int>::min();
		for (int i = 0; i < count; ++i) {
			min_delta = min(min_delta, a[i] - i);
			max_delta = max(max_delta, a[i] - i);
		}
		for (int i = 0; i < max_delta - min_delta + 1; ++i) {
			count_delta[i] = 0;
			sum_delta[i] = 0;
		}
		for (int i = 0; i < count; ++i) {
			int d = a[i] - i - min_delta;
			++count_delta[d];
			sum_delta[d] += a[i] - i;
		}
		for (int i = 1; i < max_delta - min_delta + 1; ++i) {
			count_delta[i] += count_delta[i - 1];
			sum_delta[i] += sum_delta[i - 1];
		}
	}
};

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		--val;
		a[val] = i;
	}
	vector<Block> s((n - 1) / M + 1);
	long long num_inversions = 0;
	for (int k = 0; k < n; ++k) {
		int block_idx = a[k] / M;

		int lcount = s[block_idx].count_val_mod_M[a[k] % M];
		for (int i = 0; i < block_idx; ++i) {
			lcount += s[i].count;
		}
		num_inversions += k - lcount;
		s[block_idx].add(a[k]);

		int low = -n * 2;
		int high = n * 2;
		for (; high - low > 1; ) {
			int delta = (low + high) / 2;
			int count = 0;
			int accumulated_count = 0;
			for (int i = 0; i < s.size(); ++i) {
				int threshold = delta + accumulated_count;
				count += s[i].get_count_delta(threshold);
				accumulated_count += s[i].count;
			}
			if (count >= (k + 2) / 2) {
				high = delta;
			}
			else {
				low = delta;
			}
		}
		long long results = num_inversions;
		int accumulated_count = 0;
		for (int i = 0; i < s.size(); ++i) {
			int threshold = high + accumulated_count;
			results += s[i].get_sum_of_diff(threshold);
			accumulated_count += s[i].count;
		}
		printf("%lld ", results);
	}
	printf("\n");
	return 0;
}