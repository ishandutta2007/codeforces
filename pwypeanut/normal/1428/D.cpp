#include <bits/stdc++.h>
using namespace std;

int N, A[100005], match_right[100005];
bool used[100005];
vector< pair<int, int> > places;
vector<int> ones, twos, threes;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	int lastnonzero = 1;
	for (int i = 0; i < N; i++) {
		if (A[i] != 0) lastnonzero = A[i];
	}
	if (lastnonzero != 1) {
		printf("-1\n");
		return 0;
	}
	memset(match_right, -1, sizeof(match_right));
	for (int i = N - 1;  i >= 0; i--) {
		if (A[i] == 0) continue;
		if (A[i] == 1) ones.push_back(i);
		if (A[i] == 2) {
			if (ones.size() == 0) {
				printf("-1\n");
				return 0;
			}
			match_right[i] = ones.back();
			used[ones.back()] = 1;
			ones.pop_back();
			twos.push_back(i);
		}
		if (A[i] == 3) {
			if (ones.size() == 0 && twos.size() == 0 && threes.size() == 0) {
				printf("-1\n");
				return 0;
			}
			if (twos.size() > 0) {
				match_right[i] = twos.back();
				twos.pop_back();
			} else if (threes.size() > 0) {
				match_right[i] = threes.back();
				threes.pop_back();
			} else {
				match_right[i] = ones.back();
				ones.pop_back();
			}
			threes.push_back(i);
		}
	}
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) continue;
		if (A[i] == 1) {
			if (!used[i]) places.push_back(make_pair(i + 1, i + 1));
		}
		if (A[i] == 2) {
			places.push_back(make_pair(i + 1, i + 1));
			places.push_back(make_pair(i + 1, match_right[i] + 1));
		}
		if (A[i] == 3) {
			places.push_back(make_pair(i + 1, i + 1));
			places.push_back(make_pair(i + 1, match_right[i] + 1));
		}
	}
	printf("%d\n", places.size());
	for (int i = 0; i < places.size(); i++) printf("%d %d\n", places[i].first, places[i].second);
			
}