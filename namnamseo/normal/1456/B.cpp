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

const int maxn = int(1e5) + 10;

int n;
int a[maxn];

int cm[50];

map<int,pp> m[50];
int bc[maxn][50];

int main()
{
	cin >> n;
	rrep(i, n) cin >> a[i];

	rep(i, 30) {
		m[i][0] = {0, -1};
	}

	int ans = n+1;

	rrep(i, n) {
		int im = 0;
		for(int j=29; 0<=j; --j) {
			im = (im<<1) | (1&(a[i]>>j));
			bc[i][j] = bc[i-1][j] + (im&1);

			cm[j] ^= im;
			auto it = m[j].find(cm[j]^1);
			if (it != m[j].end()) {
				auto [v1, v2] = it->y;
				int use = v1;
				if (use != -1 && (im&1) && (bc[i][j] == bc[use][j]+1)) {
					use = v2;
				}
				if (use != -1  && (!(im&1) || bc[i][j] != bc[use][j]+1)) {
					ans = min(ans, i-use-2);
				}
			}

			it = m[j].find(cm[j]);
			if (it == m[j].end()) {
				m[j][cm[j]] = {i, -1};
			} else if (bc[it->y.x][j] != bc[i][j]) {
				m[j][cm[j]] = {i, it->y.x};
			} else {
				m[j][cm[j]] = {i, it->y.y};
			}
		}
	}

	if (ans > n) ans = -1;
	cout << ans << endl;

	return 0;
}