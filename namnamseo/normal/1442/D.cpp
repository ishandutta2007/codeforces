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

const int maxn = int(3e3) + 10;

int n, k;
int s[maxn];
ll arr[maxn][maxn];

ll dp[maxn];

void apply(int l, int r) {
	for(int i=l; i<=r; ++i) {
		ll v = arr[i][s[i]];
		int h = s[i];
		for(int j=k-h-1; 0<=j; --j) {
			if (dp[j+h] < dp[j]+v) {
				dp[j+h] = dp[j]+v;
			}
		}
	}
}

ll ans;

void f(int l, int r) {
	if (l != r) {
		ll tmp[maxn];
		copy(dp, dp+k+1, tmp);

		int mid = (l+r)/2;
		apply(mid+1, r);
		f(l, mid);

		copy(tmp, tmp+k+1, dp);
		apply(l, mid);
		f(mid+1, r);
		return;
	}

	for(int i=0; i<=s[l]; ++i) {
		ans = max(ans, dp[k-i] + arr[l][i]);
	}
}

int main()
{
	cppio();
	cin >> n >> k;
	rrep(i, n) {
		cin >> s[i];
		rrep(j, s[i]) {
			int t; cin >> t;
			if (j <= k) arr[i][j] = arr[i][j-1] + t;
		}
		s[i] = min(s[i], k);
	}

	fill(dp+1, dp+k+1, -(1ll<<60));
	f(1, n);

	cout << ans << '\n';

	return 0;
}