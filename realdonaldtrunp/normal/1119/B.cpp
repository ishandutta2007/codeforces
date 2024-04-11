#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

#define MAX 1002

int n;
int h;
vector<int> v;

long long int dp[MAX][MAX];
vector<int> r;
bool ok(int a) {
	r.clear();
	for (int i = 0; i <= a; i++) {
		r.push_back(v[i]);
	}
	sort(r.begin(), r.end());
	reverse(r.begin(), r.end());
	long long int ff = 0;
	for (int i = 0; i < r.size(); i+=2) {
		ff += r[i];
	}
	return ff <= h;
}

int main() {
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	int mint = 0;
	int maxt = v.size()-1;
	while (mint + 1 < maxt) {
		int mid = (mint + maxt) /2;
		if (ok(mid)) {
			mint = mid;
		}
		else {
			maxt = mid;
		}
	}
	if (ok(maxt)) {
		mint = maxt;
	}
	else {
		maxt = mint;
	}
	cout << maxt+1 << endl;
	/*for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = LLONG_MAX;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < MAX; j++) {
			if (dp[i][j] == LLONG_MAX)continue;
			//skip
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			long long int nxt = dp[i][j] + v[i];
			if (nxt > h) {
				continue;
			}
			int go = i + 2;
			go = min(go, (int)v.size());
			int am = j + go - i;
			dp[go][am] = min(dp[go][am], nxt);
		}
	}
	int ans = 0;
	for (int j = 0; j < MAX; j++) {
		if (dp[v.size()][j] == LLONG_MAX) {

		}
		else {
			ans = j;
		}
	}
	cout << ans << endl;*/
	return 0;
}