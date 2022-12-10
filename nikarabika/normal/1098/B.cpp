//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

string str = "ATCG";
int M;

struct Mat {
	char **haha;
	int n, m;
	Mat(int nn, int mm) {
		n = nn;
		m = mm;
		haha = (char **) malloc(n * sizeof(char *));
		for (int i = 0; i < n; i++) {
			haha[i] = (char *) malloc((m + 1) * sizeof (char));
			haha[i][m] = 0;
		}
	}
	char *operator[](int i) {
		return haha[i];
	}
};

int solve(Mat s, int n, int m) {
	int ans = -1, tx, ty;
	for (int t1 = 0; t1 < 4; t1++)
		for (int t2 = t1 + 1; t2 < 4; t2++) {
			int cur = 0;
			int t3 = -1, t4 = -1;
			for (int i = 0; i < 4; i++)
				if (t1 != i and t2 != i)
					if (t3 == -1) t3 = i;
					else t4 = i;
			for (int i = 0; i < n; i++) {
				char c[2];
				if (i & 1) {
					c[0] = str[t1];
					c[1] = str[t2];
				}
				else {
					c[0] = str[t3];
					c[1] = str[t4];
				}
				int val[2] = {0, 0};
				for (int j = 0; j < m; j++)
					for (int k = 0; k < 2; k++)
						val[k] += s[i][j] == c[j & 1 ^ k];
				cur += max(val[0], val[1]);
			}
			if (cur > ans) {
				ans = cur;
				tx = t1;
				ty = t2;
			}
		}
	int t1 = tx,
		t2 = ty;
	int t3 = -1, t4 = -1;
	for (int i = 0; i < 4; i++)
		if (t1 != i and t2 != i)
			if (t3 == -1) t3 = i;
			else t4 = i;
	for (int i = 0; i < n; i++) {
		char c[2];
		if (i & 1) {
			c[0] = str[t1];
			c[1] = str[t2];
		}
		else {
			c[0] = str[t3];
			c[1] = str[t4];
		}
		int val[2] = {0, 0};
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 2; k++)
				val[k] += s[i][j] == c[j & 1 ^ k];
		int cur = max_element(val, val + 2) - val;
		for (int j = 0; j < m; j++)
			s[i][j] = c[j & 1 ^ cur];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	Mat s(n, m),
		t(m, n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++)
			t[j][i] = s[i][j];
	}
	if (solve(s, n, m) > solve(t, m, n)) {
		for (int i = 0; i < n; i++)
			cout << s[i] << '\n';
	}
	else {
		for (int i = 0; i < n; i++, cout << '\n')
			for (int j = 0; j < m; j++)
				cout << t[j][i];
	}
	return 0;
}