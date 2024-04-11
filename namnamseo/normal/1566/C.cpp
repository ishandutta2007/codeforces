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

int n;
char s[2][maxn];

int Solve(int l, int r) {
	if (l > r) return 0;
	int ans = 0;
	int last_use = -1;
	for (int i=l; i<=r; ++i) {
		if (s[0][i] == '0') {
			ans += 1;
			if (l <= i-1 && s[0][i-1] == '1' && last_use != i-1) {
				++ans;
			} else if (i+1 <= r && s[0][i+1] == '1') {
				++ans;
				last_use = i+1;
			}
		} else {
		}
	}
	return ans;
}

void Work() {
	cin >> n;
	cin >> (s[0]+1);
	cin >> (s[1]+1);

	int ans = 0;
	int lst = 0;
	rrep(i, n) {
		if (s[0][i] != s[1][i]) {
			ans += 2 + Solve(lst+1, i-1);
			lst = i;
		}
	}
	ans += Solve(lst+1, n);

	cout << ans << '\n';
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