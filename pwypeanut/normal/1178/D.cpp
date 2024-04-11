#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int N;

int main() {
	scanf("%d", &N);
	vector< pair<int, int> > ans;
	for (int i = 0; i < N; i++) ans.push_back(make_pair(i+1, (i+1)%N+1));
	int next_prime = N;
	while (!is_prime(next_prime)) next_prime++;
	assert((next_prime - N) * 2 <= N);
	for (int i = 0; i < next_prime - N; i++) {
		if (i % 2 == 0) ans.push_back(make_pair(i/2*4+1, i/2*4+3));
		else ans.push_back(make_pair(i/2*4+2, i/2*4+4));
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
}