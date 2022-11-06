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

const int MAXN = 55;
int psum[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int get(int r1, int r2, int c1, int c2) {
	return psum[r2][c2] - psum[r1][c2] - psum[r2][c1] + psum[r1][c1];
}
///

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	F0R(i, n) {
		string s; cin >> s;
		F0R(j, n)
			psum[i+1][j+1] = s[j] == '#';
	}
	F0R(i, n)
		F0R(j, n)
			psum[i+1][j+1] += psum[i+1][j] + psum[i][j+1] - psum[i][j];
	FOR(id, 1, n+1)
		FOR(jd, 1, n+1)
			F0R(i, n-id+1)
				F0R(j, n-jd+1) {
					int ni = i+id;
					int nj = j+jd;
					if(id == 1 && jd == 1) dp[i][j][ni][nj] = get(i, ni, j, nj);
					else {
						dp[i][j][ni][nj] = max(id,jd);
						FOR(k, i, i+id)
							dp[i][j][ni][nj] = min(dp[i][j][ni][nj], dp[i][j][k][nj]+dp[k][j][ni][nj]);
						FOR(k, j, j+jd)
							dp[i][j][ni][nj] = min(dp[i][j][ni][nj], dp[i][j][ni][k]+dp[i][k][ni][nj]);
					}
				}
	cout << dp[0][0][n][n] << endl;
///
	return 0;
}