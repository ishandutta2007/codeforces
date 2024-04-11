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

const int maxn = 100010;

int n;
int a[maxn];

int main()
{
	cppio();

	int tc; cin >> tc;
for(;tc--;) {
	cin >> n;
	rrep(i, n) cin >> a[i];
	int pmx = int(-1e9)-1;
	int ans = 0;
	rrep(i, n) {
		int t = a[i];
		if (pmx > t) {
			int df = pmx - t;
			rep(j, 60) if ((1ll<<j) > df) {
				ans = max(ans, j);
				break;
			}
		}
		pmx = max(pmx, t);
	}
	cout << ans << '\n';
}

	return 0;
}