#include <bits/stdc++.h>
using namespace std;

int N, A[5], B[5], wins[5], pt[5];

int points(long long w, int t) {
	if (w * 2 > t) return 500;
		else if (w * 4 > t) return 1000;
		else if (w * 8 > t) return 1500;
		else if (w * 16 > t) return 2000;
		else if (w * 32 > t) return 2500;
		else return   3000;
	}

int main() {
	scanf("%d", &N);
	for (int j = 0; j < 5; j++) scanf("%d", &A[j]);
	for (int j = 0; j < 5; j++) scanf("%d", &B[j]);
	for (int j = 0; j < 5; j++) {
		wins[j] += (A[j] != -1);
		wins[j] += (B[j] != -1);
	}
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < 5; j++) {
			int x;
			scanf("%d", &x);
			if (x != -1) wins[j]++;
		}
	}
	
	for (int j = 0; j < 5; j++) {
		long long w = wins[j], t = N;
		if (w * 2 > t) pt[j] = 500;
		else if (w * 4 > t) pt[j] = 1000;
		else if (w * 8 > t) pt[j] = 1500;
		else if (w * 16 > t) pt[j] = 2000;
		else if (w * 32 > t) pt[j] = 2500;
		else pt[j] = 3000;
	}
	long long score0 = 0, score1 = 0;
	for (int j = 0; j < 5; j++) {
		if (A[j] == -1) continue;
		score0 += pt[j] - pt[j] / 250 * A[j];
	}
	for (int j = 0; j < 5; j++) {
		if (B[j] == -1) continue;
		score1 += pt[j] - pt[j] / 250 * B[j];
	}
	if (score0 > score1) {
		printf("0\n");
		return 0;
	}
	vector<int> whacks;
	for (int j = 0; j < 5; j++) {
		for (int bound = 1; bound <= 6; bound++) {
			long long w = wins[j], t = N;
			long long bot = 0, top = 1000000000, mid;
			while (bot + 1 < top) {
				mid = (bot + top) / 2;
				w += mid;
				t += mid;
				int pt = points(w, t);
				if (pt <= 500 * bound) top = mid;
				else bot = mid;
				w -= mid;
				t -= mid;
			}
			whacks.push_back(bot);
			whacks.push_back(bot + 1);
			bot = 0;
			top = 100000000;
			while (bot + 1 < top) {
				mid = (bot + top) / 2;
				t += mid;
				int pt = points(w, t);
				if (pt > 500 * bound) top = mid;
				else bot = mid;
				t -= mid;
			}
			whacks.push_back(bot);
			whacks.push_back(bot + 1);
		}
	}
	sort(whacks.begin(), whacks.end());
	whacks.resize(unique(whacks.begin(), whacks.end()) - whacks.begin());
	int ans = 1000000008;
	for (int i = 0; i < (1<<5); i++) {
		bool flag = 0;
		for (int j = 0; j < 5; j++) if ((i & (1 << j)) && A[j] == -1) flag = 1;
		if (flag) continue;
		int mid;
		for (int j = 0; j < whacks.size(); j++) {
			mid = whacks[j];
			//printf("%d\n", mid);
			for (int j = 0; j < 5; j++) if (i & (1 << j)) wins[j] += mid;
			for (int j = 0; j < 5; j++) {
				long long w = wins[j], t = N + mid;
				if (w * 2 > t) pt[j] = 500;
				else if (w * 4 > t) pt[j] = 1000;
				else if (w * 8 > t) pt[j] = 1500;
				else if (w * 16 > t) pt[j] = 2000;
				else if (w * 32 > t) pt[j] = 2500;
				else pt[j] = 3000;
			}
			long long score0 = 0, score1 = 0;
			for (int j = 0; j < 5; j++) {
				if (A[j] == -1) continue;
				score0 += pt[j] - pt[j] / 250 * A[j];
			}
			for (int j = 0; j < 5; j++) {
				if (B[j] == -1) continue;
				score1 += pt[j] - pt[j] / 250 * B[j];
			}
			if (score0 > score1) ans = min(ans, mid);
			for (int j = 0; j < 5; j++) if (i & (1 << j)) wins[j] -= mid;
		}
	}
	if (ans == 1000000008) printf("-1\n");
	else printf("%d\n", ans);
}