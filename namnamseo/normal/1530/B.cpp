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

const int maxn = 50;

int n, m;

char a[maxn][maxn];

vector<pp> bor;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int Try(int si) {
	rrep(i, n) {
		fill(a[i]+1, a[i]+m+1, '0'); a[i][m+1] = 0;
	}

	int did = 0;
	auto Do = [&](pp pt) {
		auto [x, y] = pt;
		rep(d, 8) {
			int nx = x+dx[d], ny = y+dy[d];
			if (!(1<=nx && 1<=ny && nx<=n && ny<=m)) continue;
			if (a[nx][ny] == '1') return;
		}
		a[x][y] = '1';
		++did;
	};

	int bs = sz(bor);
	si %= bs;
	for (int i=si; i<bs; ++i) Do(bor[i]);
	rep(i, si) Do(bor[i]);
	return did;
}

void Work() {
	cin >> n >> m;

	bor.clear();
	rrep(j, m) bor.eb(1, j);
	for (int i=2; i<=n; ++i) bor.eb(i, m);
	for (int j=2; j<=m; ++j) bor.eb(n, m+1-j);
	for (int i=2; i<n; ++i) bor.eb(n+1-i, 1);

	int mx = 0, mi = 0;
	rep(i, 4) {
		int v = Try(i);
		if (mx < v) {
			mx = v;
			mi = i;
		}
	}

	Try(mi);

	rrep(i, n) {
		cout << (a[i]+1) << '\n';
	}
	cout << '\n';
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}