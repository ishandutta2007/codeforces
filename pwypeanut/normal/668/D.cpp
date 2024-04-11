#include <bits/stdc++.h>
using namespace std;

int Q;
vector< pair< int, pair<int, int> > > V;
vector<int> positions;
vector< vector<int> > times, fenwick;

void update(int pos, int ti, int del) {
	ti++;
	for (int i = ti; i <= fenwick[pos].size(); i += (i & (-i))) fenwick[pos][i - 1] += del;
}

int query(int pos, int ti) {
	ti++;
	int ans = 0;
	for (int i = ti; i > 0; i -= (i & (-i))) ans += fenwick[pos][i - 1];
	return ans;
}

int main() {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V.push_back(make_pair(a, make_pair(b, c)));
	}
	for (int i = 0; i < Q; i++) positions.push_back(V[i].second.second);
	sort(positions.begin(), positions.end());
	positions.resize(unique(positions.begin(), positions.end()) - positions.begin());
	for (int i = 0; i < positions.size(); i++) {
		vector<int> v;
		times.push_back(v);
	}
	for (int i = 0; i < Q; i++) {
		int pos = lower_bound(positions.begin(), positions.end(), V[i].second.second) - positions.begin();
		times[pos].push_back(V[i].second.first);
	}
	for (int i = 0; i < positions.size(); i++) sort(times[i].begin(), times[i].end());
	for (int i = 0; i < positions.size(); i++) times[i].resize(unique(times[i].begin(), times[i].end()) - times[i].begin());
	fenwick = times;
	for (int i = 0; i < fenwick.size(); i++) {
		for (int j = 0; j < fenwick[i].size(); j++) fenwick[i][j] = 0;
	}
	for (int i = 0; i < Q; i++) {
		int pos = lower_bound(positions.begin(), positions.end(), V[i].second.second) - positions.begin();
		int ti = lower_bound(times[pos].begin(), times[pos].end(), V[i].second.first) - times[pos].begin();
		if (V[i].first == 1) update(pos, ti, 1);
		else if (V[i].first == 2) update(pos, ti, -1);
		else printf("%d\n", query(pos, ti));
	}
}