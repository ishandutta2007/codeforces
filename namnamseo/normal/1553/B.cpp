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
char u[maxn];

void Work() {
	cin >> (s+1);
	cin >> (t+1);
	n = strlen(s+1);
	m = strlen(t+1);

	bool oke = 0;
	rrep(i, n) {
		for (int j=i; j<=n; ++j) {
			int ui = 0;
			for (int k=i; k<j; ++k) u[ui++] = s[k];
			u[ui++] = s[j];
			for (int k=j-1; 1<=k && ui<m; --k) u[ui++] = s[k];
			u[ui] = 0;
			if (ui != m || strcmp(t+1, u)) continue;
			oke = 1; break;
		}
		if (oke) break;
	}

	cout << (oke ? "YES" : "NO") << '\n';
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