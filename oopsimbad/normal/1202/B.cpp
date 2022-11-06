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

const int D = 10;
int d[D][D][D][D], ans[D][D];
void preCalc() {
	F0R(a,D) F0R(b,D) F0R(i,D) F0R(j,D) d[a][b][i][j] = 30;
	F0R(a,D) F0R(b,D) F0R(i,D) F0R(j,D) F0R(s,D) if(i||j) d[a][b][s][(s+i*a+j*b)%10] = min(d[a][b][s][(s+i*a+j*b)%10],i+j);
}
///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	preCalc();
	string s; cin >> s;
	int p = 0;
	F0R(i, s.length()) {
		int c = s[i]-'0';
		if(i == 0 && c == 0) continue;
		F0R(a,D) F0R(b,D) {
			if(d[a][b][p][c] == 30) ans[a][b] = -1;
			if(ans[a][b] == -1) continue;
			ans[a][b] += d[a][b][p][c]-1;
		}
		p = c;
	}
	F0R(i, D) {
		F0R(j, D) cout << ans[i][j] << " ";
		cout << endl;
	}
///
	return 0;
}