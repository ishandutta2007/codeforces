//sobskdrbhvk!
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

const int maxn = 400 + 10,
	  maxm = 2.5e5 + 10;
LL dp[maxn][maxn],
   pos[maxn],
   con[maxm];
int ptr[maxn][maxn],
	ord[maxm],
	frm[maxm],
	too[maxm],
	heal[maxm],
	n, m;

bool can(int id, LL val) {
	LL cur = 0;
	int cnt = 0;
	for (int i = frm[id]; i < too[id]; i++) {
		LL curval = (pos[i + 1] - pos[i]) * con[id];
		if (curval > val)
			return false;
		if (curval > cur)
			cur = val, cnt++;
		if (cnt > heal[id])
			return false;
		cur -= curval;
	}
	return true;
}

LL get(int id) {
	for (int j = 0; j <= heal[id]; j++)
		dp[frm[id]][j] = 0;
	for (int i = frm[id] + 1; i <= too[id]; i++) {
		dp[i][0] = 1e18;
		for (int j = 1; j <= heal[id]; j++) {
			ptr[i][j] = (j == 1) ? frm[id] : ptr[i][j - 1];
			while (ptr[i][j] < i and dp[ptr[i][j]][j - 1] < (pos[i] - pos[ptr[i][j]]) * con[id])
				ptr[i][j]++;
			LL best = 1e18;
			if (ptr[i][j] < i)
				smin(best, dp[ptr[i][j]][j - 1]);
			if (ptr[i][j] > frm[id])
				smin(best, (pos[i] - pos[ptr[i][j] - 1]) * con[id]);
			dp[i][j] = best;
			//cout << i << ' ' << j << ' ' << ptr[i][j] << ' ' << frm[id] << ' ' << (pos[i] - pos[ptr[i][j] - 1]) * con[id] << ' ' << dp[i][j] << '\n';
		}
	}
	return dp[too[id]][heal[id]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	srand(time(0));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> pos[i];
	for (int i = 0; i < m; i++)
		cin >> frm[i] >> too[i] >> con[i] >> heal[i], heal[i]++, frm[i]--, too[i]--;
	iota(ord, ord + m, 0);
	random_shuffle(ord, ord + m);
	LL ans = 0;
	for (int i = 0; i < m; i++) {
		if (!can(ord[i], ans))
			ans = get(ord[i]);
	}
	cout << ans << endl;
	return 0;
}