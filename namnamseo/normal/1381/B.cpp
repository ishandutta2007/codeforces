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

const int MAX_N = 2010;

int n;

int p  [MAX_N * 2];
int jmp[MAX_N * 2];
int df [MAX_N * 2];

bitset<MAX_N * 4> dp[MAX_N * 2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;
for(;tc--;) {
	cin >> n;
	rep(i, 2*n) cin >> p[i];

	vector<int> stk;
	rep(i, 2*n) {
		while (stk.size()) {
			int t = stk.back();
			if (p[t] > p[i]) break;
			jmp[t] = i;
			df[t] = (i-t);
			stk.pop_back();
		}
		stk.pb(i);
	}

	for (int x : stk) {
		jmp[x] = 2*n;
		df[x] = (2*n - x);
	}

	for(int i=0; i<=2*n; ++i) dp[i].reset();
	dp[0].set(2*n);

	rep(i, 2*n) {
		int j = jmp[i], d = df[i];
		//cout << i << ':' << j << ' ' << d << endl;
		dp[j] |= (dp[i] << d);
		dp[j] |= (dp[i] >> d);
	}

	cout << (dp[2*n][2*n] ? "YES" : "NO") << '\n';
}

	return 0;
}