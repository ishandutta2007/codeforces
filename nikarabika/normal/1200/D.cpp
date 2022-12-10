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

const int maxn = 2e3 + 10;
string s[maxn];
int sum[maxn][maxn],
	n, k;

void add(int i, int ii, int j, int jj) {
	ii++, jj++;
	smax(i, 0);
	smax(j, 0);
	smin(ii, n);
	smin(jj, n);
	assert(i<ii);
	assert(j<jj);
	sum[i][j]++;
	sum[i][jj]--;
	sum[ii][j]--;
	sum[ii][jj]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		int first = -1,
			last = -1;
		for (int j = 0; j < n; j++)
			if (s[i][j] == 'B') {
				if (!~first)
					first = j;
				last = j;
			}
		if (!~first)
			add(0, n - 1, 0, n - 1);
		else if (last - first < k)
			add(i - k + 1, i, last - (k - 1), first);
	}
	for (int j = 0; j < n; j++) {
		int first = -1,
			last = -1;
		for (int i = 0; i < n; i++)
			if (s[i][j] == 'B') {
				if (!~first)
					first = i;
				last = i;
			}
		if (!~first)
			add(0, n - 1, 0, n - 1);
		else if (last - first < k)
			add(last - (k - 1), first, j - k + 1, j);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i)
				sum[i][j] += sum[i - 1][j];
			if (j)
				sum[i][j] += sum[i][j - 1];
			if (i and j)
				sum[i][j] -= sum[i - 1][j - 1];
			smax(ans, sum[i][j]);
		}
	cout << ans << endl;
	return 0;
}