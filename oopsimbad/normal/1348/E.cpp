#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int MAXK = 505;
ll best[2][MAXK];
int rec[2][MAXK];
int ind[2][MAXK];
///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, K; cin >> n >> K;
	F0R(i, K)
		rec[0][i] = rec[1][i] = -1;
	rec[1][0] = 0;
	ind[1][0] = 0;
	FOR(i, 1, n+1) {
		int a, b; cin >> a >> b;
		int z = i&1;
		F0R(j, K) {
			if(rec[z][j] == i-1) {
				int k = ind[z][j];
				for(int v = 0; v <= a && v < K; v++) {
					int w = (b-K+(a-v)%K)%K;
					int add = 0;
					if((a-v)%K+b < K) {
						if(a%K != v)
							continue;
						w = b;
					}
					int nb = w+k;
					int na = v+j;
					if(na >= K) {
						na -= K;
						add++;
					}
					if(nb >= K) {
						nb -= K;
						add++;
					}
					if(rec[z^1][na] != i) {
						rec[z^1][na] = i;
						best[z^1][na] = 0;
						ind[z^1][na] = nb;
					}
					best[z^1][na] = max(best[z^1][na],best[z][j]+(a-v)/K+(b+(a-v)%K)/K+add);
				}
			}
		}
	}
	ll ans = 0;
	F0R(i, K)
		ans = max(ans, max(best[0][i],best[1][i]));
	cout << ans << endl;
///
	return 0;
}