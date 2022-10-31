#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void one_case(int n)
{
	vector<int> h(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	struct Segment {
		int min_h_idx;
		long long max_f;
		long long prefix_f;
	};
	vector<Segment> segments;
	vector<long long> f(n);
	int min_h_idx = 0;
	for (int i = 0; i < n; ++i) {
		if (h[i] < h[min_h_idx]) {
			min_h_idx = i;
		}
		f[i] = b[min_h_idx];
		long long next_f = -(1LL << 62);
		while (!segments.empty()) {
			const auto& seg = segments.back();
			if (h[seg.min_h_idx] < h[i]) {
				f[i] = max(f[i], seg.prefix_f + max(0, b[i]));
				break;
			}
			f[i] = max(f[i], seg.max_f + b[i]);
			next_f = max(next_f, seg.max_f);
			segments.pop_back();
		}
		segments.push_back({ i, max(next_f, f[i]), f[i] });
		if (segments.size() >= 2) {
			segments.back().prefix_f = max(segments.back().prefix_f, segments[segments.size() - 2].prefix_f);
		}
	}
	cout << f[n - 1] << endl;
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		one_case(n);
	}
	return 0;
}