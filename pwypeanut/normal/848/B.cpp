#include <bits/stdc++.h>
using namespace std;

int N, W, H, G[100005], P[100005], T[100005], ending[100005];
vector<int> grp[300005];

bool cmp(int x, int y) {
	return P[x] < P[y];
}

int main() {
	scanf("%d%d%d", &N, &W, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &G[i], &P[i], &T[i]);
		int val = P[i] - T[i];
		grp[val + 100005].push_back(i);
	}
	for (int i = 0; i <= 300000; i++) {
		vector<int> h, v, t;
		for (int j = 0; j < grp[i].size(); j++) {
			if (G[grp[i][j]] == 1) v.push_back(grp[i][j]);
			else h.push_back(grp[i][j]);
		}
		sort(h.begin(), h.end(), cmp);
		sort(v.begin(), v.end(), cmp);
		for (int j = 0; j < v.size(); j++) t.push_back(v[j]);
		reverse(t.begin(), t.end());
		for (int j = 0; j < h.size(); j++) t.push_back(h[j]);
		vector<int> o;
		for (int j = 0; j < h.size(); j++) o.push_back(h[j]);
		for (int j = (int)v.size() - 1; j >= 0; j--) o.push_back(v[j]);
		for (int j = 0; j < t.size(); j++) ending[t[j]] = o[j];
	}
	for (int i = 0; i < N; i++) {
		if (G[ending[i]] == 1) printf("%d %d\n", P[ending[i]], H);
		else printf("%d %d\n", W, P[ending[i]]);
	}
}