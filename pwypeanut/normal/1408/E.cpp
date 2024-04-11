#include <bits/stdc++.h>
using namespace std;

int M, N, A[100005], B[100005], p[100005];
vector< pair< int, pair<int, int> > > V;
vector<int> groups[100005];

int fp(int x) {
	if (p[x] == x) return x;
	else return p[x] = fp(p[x]);
}

void merge(int x, int y) {
	x = fp(x);
	y = fp(y);
	p[x] = y;
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < M; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	for (int i = 0; i < M; i++) p[i] = i;
	long long sum = 0;
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			int y;
			scanf("%d", &y);
			V.push_back(make_pair(A[i] + B[y - 1], make_pair(i, y - 1)));
			sum += A[i] + B[y - 1];
		}
	}
	sort(V.begin(), V.end(), greater< pair<int, pair<int, int> > >());
	long long cost = 0;
	for (int i = 0; i < V.size(); i++) {
		bool fail = 0;
		for (int j = 0; j < min(1, (int)groups[V[i].second.second].size()); j++) {
			if (fp(groups[V[i].second.second][j]) == fp(V[i].second.first)) {
				fail = 1;
				break;
			}
		}
		if (!fail) {
			for (int j = 0; j < min(1, (int)groups[V[i].second.second].size()); j++) {
				merge(groups[V[i].second.second][j], V[i].second.first);
			}
			groups[V[i].second.second].push_back(V[i].second.first);
			cost += V[i].first;
		}
	}
	printf("%lld\n", sum - cost);
}