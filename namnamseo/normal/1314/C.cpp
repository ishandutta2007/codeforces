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

int n, m;
ll k;

char s[1010];

pp sub[1001*1000/2];
int G [1001*1000/2];
int st[1001*1000/2];

int z;
int zc;

bool mycmp(const pp& a, const pp& b)
{
	int i, j;
	for(i=a.x, j=b.x; i<=a.y && j<=b.y; ++i, ++j) {
		if (s[i] != s[j])
			return s[i] < s[j];
	}

	return j <= b.y;
}

ll DP[2][1010];
bitset<1001> mx, mxtmp;
int mnreach[1010];

bool check(int x)
{
	const ll inf = 1e18;

	ll *dp = DP[0];
	ll *dtmp = DP[1];

	fill(dp, dp+n+1, 0);
	mx.reset();

	fill(mnreach+1, mnreach+n+1, n+1);
	for(int i=x; i<z; ++i) {
		int a, b; tie(a, b) = sub[i];
		mnreach[a] = min(mnreach[a], b);
	}

	dp[0] = 1;

	for(int step=1; step<=m; ++step) {
		fill(dtmp, dtmp+n+1, 0);
		mxtmp.reset();

		for(int i=0; i<n; ++i) {
			int t = mnreach[i+1];
			if (t <= n) {
				if (mx[i]) {
					mxtmp[t] = 1;
				} else {
					dtmp[t] += dp[i];
					if (dtmp[t] > inf) {
						mxtmp[t] = 1;
					}
				}
			}
		}

		for(int i=1; i<=n; ++i) {
			if (mxtmp[i]) continue;
			dtmp[i] += dtmp[i-1];
			if (dtmp[i] > inf || mxtmp[i-1]) mxtmp.set(i);
		}

		swap(dp, dtmp);
		swap(mx, mxtmp);
	}

	return mx[n] || (dp[n] >= k);
}

int main()
{
	cppio();
	cin >> n >> m >> k >> (s+1);

	rrep(i, n) {
		for(int j=i; j<=n; ++j) {
			sub[z++] = {i, j};
		}
	}

	sort(sub, sub+z, mycmp);

	zc = 0;
	for(int i=1; i<z; ++i) {
		if (mycmp(sub[i-1], sub[i])) {
			st[G[i] = ++zc] = i;
		} else {
			G[i] = zc;
		}
	}
	++zc;

	int l = 0, r = zc;
	while(l+1 < r) {
		int mid = (l+r)/2;
		if (check(st[mid])) {
			l = mid;
		} else {
			r = mid;
		}
	}

	int x, y; tie(x, y) = sub[st[l]];

	for(int i=x; i<=y; ++i) cout << s[i];
	cout << endl;

	return 0;
}