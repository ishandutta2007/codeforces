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

int main()
{
	cppio();
	cin >> n;
	vector<pp> cv[2];
	rrep(i, n) rrep(j, n) {
		int c = (i+j)%2;
		cv[c].eb(i, j);
	}

	while (cv[0].size() || cv[1].size()) {
		int noc; cin >> noc;
		int pick;
		if (noc == 3) {
			if (cv[0].size()) pick = 1;
			else /* if (cv[1].size()) */ pick = 2;
		} else if (noc == 1) {
			pick = 2;
		} else pick = 1;

		if (cv[pick-1].size()) {
			auto [x, y] = cv[pick-1].back();
			cv[pick-1].pop_back();
			cout << pick << ' ' << x << ' ' << y << '\n' << flush;
			continue;
		}

		pick = 3 - pick;
		auto [x, y] = cv[pick-1].back();
		cv[pick-1].pop_back();
		pick = 3;
		cout << pick << ' ' << x << ' ' << y << '\n' << flush;
	}

	return 0;
}