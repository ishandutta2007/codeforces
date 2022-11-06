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

void Work() {
	cin >> s;
	int wm = 0, qm = 0;
	rep(i, 10) {
		if (s[i] == '1') wm |= (1<<i);
		if (s[i] == '?') qm |= (1<<i);
	}

	int ans = 10;
	rep(om, 1024) {
		int m = wm | (qm & om);
		int wc[2] = {0, 0};
		int kc[2] = {5, 5};
		rep(i, 10) {
			wc[i&1] += 1&(m>>i);
			--kc[i&1];
			
			if (wc[0] > wc[1]+kc[1] || wc[1] > wc[0]+kc[0]) {
				ans = min(ans, i+1);
				break;
			}
		}
	}

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