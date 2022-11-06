#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

#define DBG if(0)

int n, m;
int z;

int a[300][300];

pp pos[300*300];

bool mR[300];
bool mC[300];

struct Sinf {
	int val;
	bool row, col;
};
vector<Sinf> surprise;

bool chk[300][300];

int ans[300][300];

int main()
{
	cppio(); cin >> n >> m; rrep(i, n) rrep(j, m) {
		cin >> a[i][j];
		pos[a[i][j]] = {i, j};
	}
	z = n*m;

	for(int i=z; 1<=i; --i) {
		int x, y; tie(x, y) = pos[i];
		bool R = !mR[x];
		bool C = !mC[y];

		if (!R && !C) continue;
		surprise.push_back({i, R, C});
		mR[x] = mC[y] = 1;
	}

	int sN = sz(surprise);

	vector<pp> cand;
	int lx = 0, ly = 0;
	for(auto &ss:surprise) {
		if (ss.row) ++lx;
		if (ss.col) ++ly;
		DBG printf("surprise of %d\n", ss.val);
		if (ss.row) {
			DBG printf("row: (%d, %d) to (%d, %d)\n",
				lx, ly-1, lx, 1);
			for(int i=ly-1; i>=1; --i) cand.eb(lx, i);
		}
		if (ss.col) {
			DBG printf("col: (%d, %d) to (%d, %d)\n",
				lx-1, ly, 1, ly);
			for(int i=lx-1; i>=1; --i) cand.eb(i, ly);
		}
		ans[lx][ly] = ss.val;
	}

	int idx = 0;
	for(int i=1; i<sN; ++i) {
		int f = surprise[i].val + 1;
		int t = surprise[i-1].val - 1;
		for(int j=t; j>=f; --j) {
			int x, y; tie(x, y) = cand[idx++];
			ans[x][y] = j;
		}
	}

	for(int i=surprise[sN-1].val-1; i>=1; --i) {
		int x, y; tie(x, y) = cand[idx++];
		ans[x][y] = i;
	}

	if (0) {
	rrep(i, n) {
		int j;
		for(j=1; j<m; ++j) if (ans[i][j] > ans[i][j+1]) break;
		for(; j<m; ++j) if (ans[i][j] < ans[i][j+1]) break;
		if (j<m) {
			cout << "-1\n";
			return 0;
		}
	}

	rrep(j, m) {
		int i;
		for(i=1; i<n; ++i) if (ans[i][j] > ans[i+1][j]) break;
		for(; i<n; ++i) if (ans[i][j] < ans[i+1][j]) break;
		if (i<n) {
			cout << "-1\n";
			return 0;
		}
	}
	}

	rrep(i, n) {
		rrep(j, m) cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}