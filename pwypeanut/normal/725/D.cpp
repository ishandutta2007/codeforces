#include <bits/stdc++.h>
using namespace std;

int N;
vector< pair<long long, int> > v;
set< pair<long long, int> > S; // cost, idx
long long B[300005], W[300005];

bool cmp(pair<long long, int> a, pair<long long, int> b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld%lld", &B[i], &W[i]);
	for (int i = 1; i < N; i++) v.push_back(make_pair(B[i], i));
	sort(v.begin(), v.end(), cmp);
	long long cur_balloon = B[0];
	int idx = upper_bound(v.begin(), v.end(), make_pair(B[0], 0), cmp) - v.begin();
	int ans = idx;
	for (int i = 0; i < idx; i++) S.insert(make_pair(W[v[i].second] - B[v[i].second] + 1, v[i].second));
	while (true) {
		if (S.size() == 0) break;
		pair<long long, int> P = *S.begin();
		//printf("picking %lld %d\n", P.first, P.second);
		S.erase(S.begin());
		if (P.first > cur_balloon) break;
		int diff = upper_bound(v.begin(), v.end(), make_pair(cur_balloon - P.first, 0), cmp) - upper_bound(v.begin(), v.end(), make_pair(cur_balloon, 0), cmp);
		idx += diff;
		idx--;
		ans = min(ans, idx);
		int prev_idx = upper_bound(v.begin(), v.end(), make_pair(cur_balloon, 0), cmp) - v.begin();
		cur_balloon -= P.first;
		
		//printf("adding %d to %d\n", prev_idx, prev_idx + diff);
		for (int i = prev_idx; i < prev_idx + diff; i++) S.insert(make_pair(W[v[i].second] - B[v[i].second] + 1, v[i].second));
	}
	printf("%d\n", ans + 1);
}