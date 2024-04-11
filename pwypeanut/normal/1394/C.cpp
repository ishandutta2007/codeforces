#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> x[500005], y[500005], v1, v2;
char S[500005];
vector< pair<int, int> > V;

int get_dist(int a, int b, int c, int d) {
	if ((a < c) == (b < d)) return max(abs(c - a), abs(b - d));
	else return abs(c - a) + abs(b - d);
}

map< pair<int, int>, pair<int, int> > memo;

pair<int, int> get_answer(int a, int b) {
	if (memo.find(make_pair(a, b)) != memo.end()) return memo[make_pair(a, b)];
	int ans = 0;
	int aans = max(max(abs(a - v1[0]), abs(v1.back() - a)), max(abs(b - v2[0]), abs(v2.back() - b)));
		int p = upper_bound(v1.begin(), v1.end(), a) - v1.begin();
		for (int i = p; i < v1.size(); i++) {
			int idx = v1[i];
			for (int j = 0; j < x[idx].size(); j++) {
				ans = max(ans, get_dist(a, b, V[x[idx][j]].first, V[x[idx][j]].second));
			}
		}
		p = upper_bound(v2.begin(), v2.end(), b) - v2.begin();
		for (int i = p; i < v2.size(); i++) {
			int idx = v2[i];
			for (int j = 0; j < y[idx].size(); j++) {
				ans = max(ans, get_dist(a, b, V[y[idx][j]].first, V[y[idx][j]].second));
			}
		}
	pair<int, int> actualans;
	if (aans > ans) actualans = make_pair(aans, ans);
	else actualans = make_pair(ans, aans);
	return memo[make_pair(a, b)] = actualans;
}

int dir[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, -1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", S);
		int b = 0, n = 0, l = strlen(S);
		for (int j = 0; j < l; j++) {
			if (S[j] == 'B') b++;
			else n++;
		}
		V.push_back(make_pair(b, n));
		x[b].push_back(i);
		y[n].push_back(i);
		v1.push_back(b);
		v2.push_back(n);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
	v2.resize(unique(v2.begin(), v2.end()) - v2.begin());
	
	int bans = (v1.back() + v1[0] + 1) / 2, nans = (v2.back() + v2[0] + 1) / 2;
	pair<int, int> curans = get_answer(bans, nans);
	
	while (1) {
		pair<int, int> best = curans;
		int bestb = bans, bestn = nans;
		for (int i = 0; i < 8; i++) {
			int newb = bans + dir[i][0], newn = nans + dir[i][1];
			if (newb + newn > 0 && newb >= 0 && newn >= 0) {
				pair<int, int> newanswer = get_answer(newb, newn);
				if (newanswer < best) {
					best = newanswer;
					bestb = newb;
					bestn = newn;
				}
			}
		}
		if (bestb == bans && bestn == nans) break;
		bans = bestb;
		nans = bestn;
		curans = best;
	}
	
	printf("%d\n", curans.first);
	for (int i = 0; i < bans; i++) printf("B");
	for (int i = 0; i < nans; i++) printf("N");
	printf("\n");
}