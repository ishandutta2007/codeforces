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
#define xy(a) a.x, a.y

const int maxc = int(1e5) + 10;

int n;
char s[maxc];

pp act[3];

int m0[1010][1010];
int ans[1010][1010];

int norm(int x) {
	if (x < 0) x = n - ((-x)%n);
	return (x+n-1)%n + 1;
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) { int cl;
	cin >> n >> cl;
	rrep(i, n) rrep(j, n) cin >> m0[i][j];
	cin >> s;
	rep(i, 3) act[i] = {i, 0};
	rep(i, cl) {
		switch(s[i]) {
		case 'R': {
			act[1].y += 1;
		} break;
		case 'L': {
			act[1].y -= 1;
		} break;
		case 'D': {
			act[0].y += 1;
		} break;
		case 'U': {
			act[0].y -= 1;
		} break;
		case 'I': {
			swap(act[1], act[2]);
		} break;
		case 'C': {
			swap(act[0], act[2]);
		} break;
		}
	}

	{ int v[3];
	rrep(i, n) { v[0] = i;
	rrep(j, n) { v[1] = j;
		v[2] = m0[i][j];
		int ni = norm(v[act[0].x] + act[0].y);
		int nj = norm(v[act[1].x] + act[1].y);
		int nx = norm(v[act[2].x] + act[2].y);
		ans[ni][nj] = nx;
	}
	} }

	rrep(i, n) {
		rrep(j, n) cout << ans[i][j] << (j == n ? '\n' : ' ');
	}

	cout << '\n';
}

	return 0;
}