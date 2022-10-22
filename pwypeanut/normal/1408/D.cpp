#include <bits/stdc++.h>
using namespace std;

int N, M;
pair<int, int> R[2005], S[2005];
vector< pair< int, int > > V;
int cnt[1000005];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d%d", &R[i].first, &R[i].second);
	for (int i = 0; i < M; i++) scanf("%d%d", &S[i].first, &S[i].second);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			V.push_back(make_pair(S[i].first - R[j].first, max(0, S[i].second - R[j].second + 1)));
			cnt[max(0, S[i].second - R[j].second + 1)]++;
			//printf("%d %d = %d %d\n", i, j, V.back().first, V.back().second);
		}
	}
	sort(V.begin(), V.end());
	int mx = 1000004, ptr = 0, ans = 1000000000;
	for (int i = 0; i <= 1000001; i++) {
		while (ptr != V.size() && V[ptr].first < i) {
			cnt[V[ptr].second]--;
			ptr++;
		}
		while (mx > 0 && cnt[mx] == 0) mx--;
		ans = min(ans, i + mx);
		//if (i < 100) printf("min %d %d\n", i, mx);
	}
	printf("%d\n", ans);
}