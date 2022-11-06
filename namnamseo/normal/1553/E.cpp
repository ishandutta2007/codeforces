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

const int maxn = int(3e5) + 10;

int n, m;
int t[maxn];
int tp[maxn];

int kc[maxn];

void Work() {
	cin >> n >> m;
	rrep(i, n) {
		cin >> t[i];
		tp[t[i]] = i;
	}

	memset(kc, 0, sizeof(int)*(n+1));
	for (int i=1; i<=n; ++i) {
		int k = tp[i] - i;
		if (k < 0) k += n;
		k %= n;
		++kc[k];
	}

	static int ans[maxn], an;
	an = 0;
	rep(k, n) if (kc[k] >= n - 2*m) {
		static int p[maxn];
		rrep(i, n) {
			int j = i+k;
			if (j > n) j -= n;
			// val: i
			// pos: j
			p[j] = tp[i];
		}

		static bool vis[maxn];
		memset(vis, 0, sizeof(bool)*(n+1));

		int cyc = 0;
		rrep(i, n) {
			if (vis[i]) continue;
			++cyc;
			for (int j=i;;) {
				vis[j] = true;
				j = p[j];
				if (j == i) break;
			}
		}

		if (n-cyc <= m) ans[an++] = k;
	}
	cout << an;
	rep(i, an) {
		cout << ' ' << ans[i];
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