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

int n, k;

int z[100][100];

int ga[100], gan;
int gb[100], gbn;

int d[100];

int main()
{
	cppio();

	cin >> n >> k;
	rrep(i, n) rrep(j, n) cin >> z[i][j];

	clock_t tgt = CLOCKS_PER_SEC * 2.5;

	int ans = int(1e9) + 10;

	ga[0] = 1;
	for( ; clock() < tgt; ) {
		gan = 1; gbn = 0;
		for(int i=2; i<=n; ++i) {
			if (rand()&1) ga[gan++] = i;
			else gb[gbn++] = i;
		}

		const int inf = int(1e9) + 10;
		fill(d+1, d+n+1, inf);
		d[1] = 0;

		for(int i=k/2; i--; ) {
			rep(b, gbn) d[gb[b]] = inf;

			rep(a, gan) {
				int va = ga[a];
				if (d[va] == inf) continue;
				rep(b, gbn) {
					int vb = gb[b];
					d[vb] = min(d[vb], d[va]+z[va][vb]);
				}
			}

			rep(a, gan) d[ga[a]] = inf;

			rep(b, gbn) {
				int vb = gb[b];
				if (d[vb] == inf) continue;
				rep(a, gan) {
					int va = ga[a];
					d[va] = min(d[va], d[vb]+z[vb][va]);
				}
			}
		}

		ans = min(ans, d[1]);
	}

	cout << ans << endl;

	return 0;
}