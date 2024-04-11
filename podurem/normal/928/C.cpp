#include <bits/stdc++.h>
 
using namespace std;

const int dd = (int)1e5 + 1;

map<pair<string, int>, vector<pair<string, int> > > G;
map<string, pair<int, int> > D;

int main() {
	int n, k;
	cin >> n;
	pair<string, int> pP, j;
	vector<pair<string, int> > F;
	for (int i = 0; i < n; ++i) {
		cin >> j.first >> j.second;
		if (i == 0) pP = j;
		cin >> k;
		F.resize(k);
		for (int s = 0; s < k; ++s)
			cin >> F[s].first >> F[s].second;
		G[j] = F;
	}

	queue<pair<string, int> > Q;
	Q.push(pP);
	D[pP.first] = { 0, pP.second };
	vector<pair<string, int> > ans;
	while ((int)Q.size()) {
		auto T = Q.front();
		Q.pop();
		if (D[T.first].second != T.second) continue;
		ans.push_back(T);
		for (auto l : G[T])
			if (D.find(l.first) == D.end() || D[l.first].first == D[T.first].first + 1 && D[l.first].second < l.second) {
				D[l.first] = { D[T.first].first + 1, l.second };
				Q.push(l);
			}
	}
	sort(ans.begin(), ans.end());
	cout << (int)ans.size() - 1 << "\n";
	for (auto i : ans) if (i != pP) {
		cout << i.first << " " << i.second << "\n";
	}
    return 0;
}