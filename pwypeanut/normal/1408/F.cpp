#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > V;

void merge(int x, int y) {
	if (y - x == 1) return;
	int m = (x + y) / 2;
	merge(x, m);
	merge(m, y);
	for (int i = x; i < m; i++) V.push_back(make_pair(i, i + m - x));
}

int main() {
	int N;
	scanf("%d", &N);
	int nextp = N;
	while (__builtin_popcount(nextp) > 1) nextp -= (nextp & (-nextp));
	merge(0, nextp);
	merge(N - nextp, N);
	printf("%d\n", V.size());
	for (int i = 0; i < V.size(); i++) printf("%d %d\n", V[i].first + 1, V[i].second + 1);
}