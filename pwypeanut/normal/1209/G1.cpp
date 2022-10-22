#include <bits/stdc++.h>
using namespace std;

int N, Q, A[200005];
vector< pair<int, pair<int, int> > > V;
vector<int> places[200005];
vector<int> meow;

int main() {
	scanf("%d%d",  &N, &Q);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) places[A[i]].push_back(i);
	for (int i = 1; i <= 200000; i++) {
		if (places[i].size() == 0) continue;
		V.push_back(make_pair(places[i][0], make_pair(-1, i)));
		V.push_back(make_pair(places[i].back(), make_pair(1, i)));
	}
	sort(V.begin(), V.end());
	int cur = 0, ans = 0;
	for (int i = 0; i < V.size(); i++) {
		cur += V[i].second.first;
		if (V[i].second.first == -1) meow.push_back(V[i].second.second);
		if (cur == 0 && (i + 1 == V.size() || V[i].first != V[i+1].first)) {
			int sum = 0, mx = 0;
			for (int j = 0; j < meow.size(); j++) {
				sum += places[meow[j]].size();
				mx = max(mx, (int)places[meow[j]].size());
			}
			ans += sum-mx;
			meow.clear();
		}
	}
	printf("%d\n", ans);
}