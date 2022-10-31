#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define P2(x) (1 << (x))

#ifdef _MSC_VER
int __builtin_popcount(int n) {
	return (n == 0) ? 0 : __builtin_popcount(n / 2) + n % 2;
}
#endif

inline int op(int mask, int a, int b) {
	if (((mask >> a) & 1) != ((mask >> b) & 1)) {
		return mask ^ P2(a) ^ P2(b);
	}
	return mask;
}
int main()
{
#ifdef _MSC_VER
	freopen("g.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int len;
	int delta;
	int n;
	cin >> len >> delta >> n;
	string str1;
	string str2;
	cin >> str1 >> str2;
	int mask1 = 0;
	int mask2 = 0;
	for (int i = 0; i < n; i++) {
		if (str1[i] == '1') {
			mask1 ^= P2(i);
		}
		if (str2[i] == '1') {
			mask2 ^= P2(i);
		}
	}

	vector<int> ra(len);
	vector<int> rb(len);
	for (int i = 0; i < len; ++i) {
		cin >> ra[i] >> rb[i]; --ra[i]; --rb[i];
	}
	vector<int> permutation(n);
	for (int i = 0; i < n; i++) {
		permutation[i] = i;
	}
	vector<int> p1(len + 1);
	vector<int> p2(len + 1);
	p1[len] = mask1;
	p2[len] = mask2;
	for (int i = len - 1; i >= 0; i--) {
		swap(permutation[ra[i]], permutation[rb[i]]);
		for (int j = 0; j < n; j++) {
			if (mask1 & P2(j)) {
				p1[i] ^= P2(permutation[j]);
			}
			if (mask2 & P2(j)) {
				p2[i] ^= P2(permutation[j]);
			}
		}
	}
	int ret1 = -1;
	int ret2 = -1;
	int ret3 = -1;
	vector<int> d(P2(n), 1000);
	vector<int> label(P2(n), -1);
	vector<int> que;
	auto add = [&](int mask, int d0, int l0) {
		if (d0 >= d[mask]) {
			return;
		}
		d[mask] = d0;
		label[mask] = l0;
		que.push_back(mask);
	};
	for (int i = len; i >= 0; i--) {
		if (i + delta <= len) {
			que.clear();
			add(p2[i + delta], 0, i + delta);
			for (int close = 0; close < que.size(); ++close) {
				int mask = que[close];
				for (int j = 0; j < n; j++) {
					add(mask ^ P2(j), d[mask] + 1, label[mask]);
				}
			}
		}
		if (n - d[p1[i]] > ret1) {
			ret1 = n - d[p1[i]];
			ret2 = i;
			ret3 = label[p1[i]] - 1;
		}
	}
	printf("%d\n%d %d\n", ret1, ret2 + 1, ret3 + 1);
	return 0;
}