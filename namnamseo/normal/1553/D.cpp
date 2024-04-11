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

const int maxn = int(2e5) + 10;

int n, m;
char s[maxn];
char t[maxn];

int dp[maxn][2];

void Work() {
	cin >> (s+1) >> (t+1);
	n = strlen(s+1);
	m = strlen(t+1);

	bool oke = 0;
	dp[0][1] = -1;
	for (int i=1; i<=n; ++i) {
		int *cd = dp[i];

		cd[0] = 0; cd[1] = -1;
		if (i >= 2) {
			cd[0] = dp[i-2][0];
			cd[1] = dp[i-2][1];
		}

		int *bd = dp[i-1];
		rep(j, 2) {
			if (bd[j^1] >= 1) {
				cd[j] = max(cd[j], bd[j^1]-1);
			}
			if (bd[j^1] < m && t[bd[j^1]+1] == s[i]) {
				cd[j] = max(cd[j], bd[j^1]+1);
			}
		}

		if (dp[i][m&1] == m && (n-i)%2 == 0) oke = 1;
	}

	cout << (oke ? "YES":"NO") << '\n';
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