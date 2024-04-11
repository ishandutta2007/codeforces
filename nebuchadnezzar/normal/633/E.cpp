#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e6 + 5;
const int bd = 20;

int n, k;
int arrv[MAXN], arrc[MAXN];
int sparse[2][bd][MAXN];
int maxbd[MAXN];

int get_v(int l, int r) {
 	int tmp = maxbd[r - l + 1];
 	return max(sparse[0][tmp][r], sparse[0][tmp][l + (1 << tmp) - 1]);
}

int get_c(int l, int r) {
 	int tmp = maxbd[r - l + 1];
 	return min(sparse[1][tmp][r], sparse[1][tmp][l + (1 << tmp) - 1]);
}

int main() {
	for (int i = 1; i < MAXN; ++i) {
	 	maxbd[i] = maxbd[i - 1];
	 	if ((1 << (maxbd[i] + 1)) <= i) {
	 	 	++maxbd[i];
	 	}
	}
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; ++i) {
	 	scanf("%d", arrv + i);
	 	arrv[i] *= 100;
	 	sparse[0][0][i] = arrv[i];
	}

	for (int i = 0; i < n; ++i) {
	 	scanf("%d", arrc + i);
	 	sparse[1][0][i] = arrc[i];
	}

	for (int j = 1; j < bd; ++j) {
 	 	for (int i = (1 << j) - 1; i < n; ++i) {
 	 	 	sparse[0][j][i] = max(sparse[0][j - 1][i], sparse[0][j - 1][i - (1 << (j - 1))]);
 	 	}
    }

	for (int j = 1; j < bd; ++j) {
 	 	for (int i = (1 << j) - 1; i < n; ++i) {
 	 	 	sparse[1][j][i] = min(sparse[1][j - 1][i], sparse[1][j - 1][i - (1 << (j - 1))]);
 	 	}
    }


    vector<int> values;
	for (int i = 0; i < n; ++i) {
	 	int l = i, r = n - 1;
	 	while (r - l > 1) {
	 	 	int mid = (r + l) / 2;
	 	 	if (get_v(i, mid) < get_c(i, mid)) {
	 	 	 	l = mid;
	 	 	} else {
	 	 	 	r = mid;
	 	 	}
	 	}
	 	values.puba(max(min(get_v(i, l), get_c(i, l)), min(get_v(i, r), get_c(i, r))));
	 	/*
	 	int best = 0;
	 	int nowmax = 0, nowmin = 1e9;
	 	for (int j = i; j < n; ++j) {
	 	 	nowmax = max(nowmax, arrv[j]);
	 	 	nowmin = min(nowmin, arrc[j]);
	 	 	best = max(best, min(nowmax, nowmin));
	 	}
	 	assert(values.back() == best);
	 	*/
	 	//cerr << values.back() << endl;
	}

	sort(bend(values));
	reverse(bend(values));

	long double ans = 0;
	long double na = (long double) k / n;
	/*
	vector<int> up, down;
	for (int i = n; i > n - k + 1; --i) {
	 	up.puba(i);
	}
	for (int i = n; i > n - k; --i) {
	 	down.puba(i);
	}

	while (szof(up) || szof(down)) {
		cerr << na << endl;
	 	if ((na > 1 || !szof(up)) && szof(down)) {
	 	 	na /= down.back();
	 	 	down.pop_back();
	 	} else {
	 	 	na *= up.back();
	 	 	up.pop_back();
	 	}
	}*/

	//cerr << na << endl;

	for (int i = n - 1; i >= k - 1; --i) {
		//cerr << na << endl;
		ans += na * values[i];
		
		if (k > 1) {
        	if (i > k) {
         	 	na *= (i - k + 1);	 	 
         	}
	 	
	 		na /= i;
	 	}
	}

	//na *= (n - k + 1);

	//ans /= na;

	printf("%.15f\n", (double) ans);

	return 0;
}