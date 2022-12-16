#include <bits/stdc++.h>

std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int>>, std::greater <std::pair <int, int>>> pq;

int N, K;

std::vector <std::pair <int, int>> ans;

int ans1 = -1, ans2 = -1;

int main () {
	scanf ("%d%d", &N, &K);
	for (int i = 1; i <= K; ++i) 
		pq.push (std::make_pair (0, i));
	for (int i = K + 1; i < N; ++i) {
		std::pair <int, int> d = pq.top ();
		pq.pop ();
		ans.push_back (std::make_pair (i, d.second));
		pq.push (std::make_pair (d.first + 1, i));
	}
	while (!pq.empty ()) {
		std::pair <int, int> d = pq.top ();
		pq.pop ();
		ans.push_back (std::make_pair (N, d.second));
		ans1 = ans2; ans2 = d.first;
	}
	printf ("%d\n", ans1 + ans2 + 2);
	for (int i = 0; i < ans.size (); ++i)
		printf ("%d %d\n", ans[i].first, ans[i].second);
}