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

const int maxn = int(3e2) + 10;
const int maxN = maxn*maxn;

int n, m, nm;
int a[maxN];
int aknd[maxN];
int asort[maxN];
vector<int> seats[maxN];
int si[maxN];

bool pie[maxn][maxn];

void Work() {
	cin >> n >> m;
	nm = n*m;
	rrep(i, nm) cin >> a[i];

	copy(a+1, a+nm+1, asort+1);
	sort(asort+1, asort+nm+1);
	rrep(i, nm) {
		auto il = lower_bound(asort+1, asort+nm+1, a[i]);
		int knd = il-asort;
		aknd[i] = knd;
	}

	for (int i=1, j; i<=nm; i=j) {
		for (j=i+1; j<=nm && asort[i] == asort[j]; ++j);
		int pl = i, pr = j-1;
		int rmin = (pl-1)/m + 1;
		int rmax = (pr-1)/m + 1;
		seats[i].clear();
		si[i] = 0;
		if (rmin == rmax) {
			for (int t=pr; pl<=t; --t) seats[i].pb(t);
			continue;
		}
		int cmin = pl-(rmin-1)*m;
		int cmax = pr-(rmax-1)*m;
		for (int t=m; cmin<=t; --t) seats[i].pb((rmin-1)*m + t);
		for (int t=m; 1<=t; --t) {
			for (int b=rmin+1; b<rmax; ++b) {
				seats[i].pb((b-1)*m + t);
			}
		}
		for (int t=cmax; 1<=t; --t) seats[i].pb((rmax-1)*m + t);
	}

	int ans = 0;
	rrep(i, n) fill(pie[i]+1, pie[i]+m+1, false);

	rrep(i, nm) {
		int k = aknd[i];
		int s = seats[k][si[k]++];
		int r = (s-1)/m + 1, c = s-(r-1)*m;
		for (int j=1; j<c; ++j) if (pie[r][j]) ++ans;
		pie[r][c] = true;
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