#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int dp[505][505], N, M, arr[1000005], values[1000005];

int f(int x, int y) {
	if (x == y) return 1;
	else if (x > y) return 1;
	else if (dp[x][y] != -1) return dp[x][y];
	//long long ans = 0;
	int mini = 1000000000, loc = 0;
	for (int i = x; i <= y; i++) {
		if (arr[i] < mini) {
			mini = arr[i];
			loc = i;
		}
	}
	int sum_le = 0, sum_re = 0;
	vector<int> le, ri;
	for (int l = x; l <= loc; l++) {
	
			long long val = f(x, l-1);
			val *= f(l, loc-1);
			val %= MOD;
			le.push_back(val);
			sum_le += val;
			sum_le %= MOD;
			
	}
	for (int r = loc; r <= y; r++) {
		long long val = f(loc+1, r);
		val *= f(r+1, y);
		val %= MOD;
		ri.push_back(val);
		sum_re += val;
		sum_re %= MOD;
	}
	long long ans = (long long)sum_le * sum_re;
	ans %= MOD;
	return dp[x][y] = ans;
}

int compute(vector<int> arr1) {
	for (int i = 0; i < arr1.size(); i++) arr[i] = arr1[i];
	for (int i = 0; i < arr1.size(); i++) for (int j = 0; j < arr1.size(); j++) dp[i][j] = -1;
	return f(0, arr1.size() - 1);
}

vector<int> locations[505];

struct node {
	int s, e, m, mx;
	node *l, *r;
	node(int _s, int _e) {
		s = _s;
		e = _e;
		m = (s + e) / 2;
		if (s == e) mx = values[s];
		else {
			l = new node(s, m);
			r = new node(m+1, e);
			mx = min(l->mx, r->mx);
		}
	}
	int qry(int qs, int qe) {
		if (qs > qe) return 1000000000;
		else if (qs <= s && e <= qe) return mx;
		else if (qs > e || s > qe) return 1000000000;
		else return min(l->qry(qs, qe), r->qry(qs, qe));
	}
} *root;

int fir[505], las[505];
long long ans = 1;

void decomp(int s, int e) {
	if (s > e) return;
	vector<int> res;
	for (int i = s; i <= e;) {
		res.push_back(values[i]);
		for (int j = 0; j < locations[values[i]].size() - 1; j++) decomp(locations[values[i]][j] + 1, locations[values[i]][j+1]-1);
		i = las[values[i]] + 1; 
	}
	ans *= compute(res);
	ans %= MOD;
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) scanf("%d", &values[i]);
	for (int i = 0; i < N; i++) locations[values[i]].push_back(i);
	root = new node(0, N-1);
	memset(fir, 63, sizeof(fir));
	memset(las, -63, sizeof(las));
	for (int i = 0; i < N; i++) fir[values[i]] = min(fir[values[i]], i);
	for (int i = 0; i < N; i++) las[values[i]] = max(las[values[i]], i);
	bool flag = 0;
	for (int i = 1; i <= M; i++) {
		if (root->qry(fir[i], las[i]) < i) flag = 1;
	}
	if (flag) {
		printf("0\n");
		return 0;
	}
	decomp(0, N-1);
	printf("%lld\n", ans);
}