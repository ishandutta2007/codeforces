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
int sl[maxN];
int sr[maxN];
int asort[maxN];

bool filled[maxn];

void Work() {
	cin >> n >> m;
	nm = n*m;
	rrep(i, nm) cin >> a[i];

	copy(a+1, a+nm+1, asort+1);
	sort(asort+1, asort+nm+1);
	rrep(i, nm) {
		auto [il, ir] = equal_range(asort+1, asort+nm+1, a[i]);
		sl[i] = il-asort;
		sr[i] = ir-asort-1;
	}

	int ans = 0;
	fill(filled+1, filled+nm+1, false);
	rrep(i, nm) {
		int mp = sr[i];
		while (filled[mp]) --mp;
		rrep(i, mp-1) if (filled[i]) ++ans;
		filled[mp] = true;
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