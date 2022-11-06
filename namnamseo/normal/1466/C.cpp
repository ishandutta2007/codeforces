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
char s[maxn];

int a3[maxn], a3n;
int a2[maxn], a2n;

bool chk[maxn];

int main()
{
	cppio();
	int tc; cin >> tc;
rep(tci, tc) {
	cin >> (s+1);
	n = strlen(s+1);

	a3n = 0;
	rrep(i, n-2) if (s[i] == s[i+2]) a3[a3n++] = i;
	a2n = 0;
	rrep(i, n-1) if (s[i] == s[i+1]) a2[a2n++] = i;
	fill(chk+1, chk+n+1, 0);

	int ans = 0;
	int i3 = 0, i2 = 0;
	while(true) {
		while (i2 < a2n) {
			if (chk[a2[i2]] || chk[a2[i2]+1]) ++i2;
			else break;
		}

		while (i3 < a3n) {
			if (chk[a3[i3]] || chk[a3[i3]+2]) ++i3;
			else break;
		}

		if (i3 == a3n && i2 == a2n) break;

		++ans;
		int pt;
		if (i3<a3n && (i2 == a2n ||
			a3[i3] < a2[i2])) {
			pt = a3[i3] + 2;
			++i3;
		} else {
			pt = a2[i2] + 1;
			++i2;
		}
		chk[pt] = 1;
	}
	cout << ans << '\n';
}
	return 0;
}