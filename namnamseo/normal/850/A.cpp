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

const int maxn = int(1e3) + 10;

int n;
int a[maxn][5];

int v[243][5];
int gp[maxn], gpn;
bitset<243> use;

void Work() {
	cin >> n;
	rep(i, n) rep(k, 5) cin >> a[i][k];
	gpn = 0;
	rep(b, n) {
		use.reset();
		bool ok = 1;
		rep(i, n) if (i != b) {
			int vv[5], msk = 0; rep(k, 5) {
				vv[k] = (a[i][k] - a[b][k]);
				msk = msk*3 + ((vv[k]>0) - (vv[k]<0) + 1);
			}
			if (use[msk]) { ok = 0; break; } use.set(msk);
			copy(vv, vv+5, v[msk]);
		}
		if (ok) rep(i, 243) if (use[i]) { rep(j, i) if (use[j]) {
			int t = 0;
			rep(k, 5) t += v[i][k] * v[j][k];
			if (t > 0) { ok = 0; break; }
		} if (!ok) break; }
		if (ok) gp[gpn++] = b+1;
	}
	cout << gpn << '\n';
	rep(i, gpn) cout << gp[i] << '\n';
}

int main()
{
	cppio();
	Work();
	return 0;
}