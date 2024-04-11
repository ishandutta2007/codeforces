#include <bits/stdc++.h>

int N, Q, max = 0;
std::deque <int> deq;
std::pair <long long, int> query[310000];
std::pair <int, int> res[310000];

int main () {
	scanf ("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		int a; scanf ("%d", &a); deq.push_back (a);
		max = std::max (max, a);
	}
	for (int i = 0; i < Q; ++i) {
		scanf ("%lld", &query[i].first), --query[i].first;
		query[i].second = i;
	}
	std::sort (query, query + Q);
	for (int t = 0, c = 0; c < Q; ++t) {
		while (c < Q && query[c].first == t) res[query[c].second] = std::make_pair (deq[0], deq[1]), ++c;
		if (deq[0] == max)
			for (; c < Q; ++c)
				res[query[c].second] = std::make_pair (max, deq[(query[c].first - t) % (N - 1) + 1]);
		if (c < Q) {
			int a = deq[0], b = deq[1]; deq.pop_front (); deq.pop_front ();
			if (a < b) std::swap (a, b);
			deq.push_front (a); deq.push_back (b);
		}
	}
	for (int i = 0; i < Q; ++i) printf ("%d %d\n", res[i].first, res[i].second);
}