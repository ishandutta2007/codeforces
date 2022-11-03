#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

std::random_device rnd_dev;
std::mt19937 rnd(clock() ^ rnd_dev());

int main() {
	int n = ri();
	struct One {
		int s1;
		int e1;
		int s2;
		int e2;
		uint64_t random;
	};
	std::vector<One> ones(n);
	for (int i = 0; i < n; i++) {
		ones[i].s1 = ri();
		ones[i].e1 = ri();
		ones[i].s2 = ri();
		ones[i].e2 = ri();
		ones[i].random = std::uniform_int_distribution<uint64_t> () (rnd);
	}
	std::vector<uint64_t> hash(n);
	{
		std::vector<int> right_sorted(n), left_sorted(n);
		std::iota(right_sorted.begin(), right_sorted.end(), 0);
		std::iota(left_sorted.begin(), left_sorted.end(), 0);
		std::sort(right_sorted.begin(), right_sorted.end(), [&] (int i, int j) { return ones[i].e1 < ones[j].e1; });
		std::sort(left_sorted.begin(), left_sorted.end(), [&] (int i, int j) { return ones[i].s1 < ones[j].s1; });
		int head = 0;
		uint64_t cur = 0;
		for (int i = 0; i < n; i++) {
			while (head < n && ones[right_sorted[head]].e1 < ones[left_sorted[i]].s1) cur ^= ones[right_sorted[head++]].random;
			hash[left_sorted[i]] ^= cur;
		}
		head = n - 1;
		cur = 0;
		for (int i = n - 1; i >= 0; i--) {
			while (head >= 0 && ones[left_sorted[head]].s1 > ones[right_sorted[i]].e1) cur ^= ones[left_sorted[head--]].random;
			hash[right_sorted[i]] ^= cur;
		}
	}
	{
		std::vector<int> right_sorted(n), left_sorted(n);
		std::iota(right_sorted.begin(), right_sorted.end(), 0);
		std::iota(left_sorted.begin(), left_sorted.end(), 0);
		std::sort(right_sorted.begin(), right_sorted.end(), [&] (int i, int j) { return ones[i].e2 < ones[j].e2; });
		std::sort(left_sorted.begin(), left_sorted.end(), [&] (int i, int j) { return ones[i].s2 < ones[j].s2; });
		int head = 0;
		uint64_t cur = 0;
		for (int i = 0; i < n; i++) {
			while (head < n && ones[right_sorted[head]].e2 < ones[left_sorted[i]].s2) cur ^= ones[right_sorted[head++]].random;
			hash[left_sorted[i]] ^= cur;
		}
		head = n - 1;
		cur = 0;
		for (int i = n - 1; i >= 0; i--) {
			while (head >= 0 && ones[left_sorted[head]].s2 > ones[right_sorted[i]].e2) cur ^= ones[left_sorted[head--]].random;
			hash[right_sorted[i]] ^= cur;
		}
	}
	bool res = true;
	for (auto i : hash) if (i) res = false;
	std::cout << (res ? "YES" : "NO") << std::endl;
	return 0;
}