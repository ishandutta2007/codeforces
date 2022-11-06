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
int r[maxn][5];

int s[maxn];

void Work() {
	cin >> n;
	rrep(i, n) rep(j, 5) cin >> r[i][j];

	iota(s+1, s+n+1, 1);
	sort(s+1, s+n+1, [&](const int& a, const int& b) {
		int w = 0;
		rep(i, 5) w += (r[a][i] < r[b][i]);
		return w>=3;
	});

	int x = s[1];
	rrep(i_, n-1) {
		int y = s[i_+1];
		int w = 0;
		rep(j, 5) w += (r[x][j] < r[y][j]);
		if (w < 3) {
			x = -1;
			break;
		}
	}

	cout << x << '\n';
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