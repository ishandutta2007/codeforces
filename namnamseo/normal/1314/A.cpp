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

int n;
pp d[200010];

int main()
{
	cppio(); cin >> n;
	rrep(i, n) cin >> d[i].x;
	rrep(i, n) cin >> d[i].y;
	sort(d+1, d+n+1);

	int pt = 1;

	multiset<int> s;
	ll ans = 0;
	ll hand = 0;
	int c = 0;

	while (pt <= n || hand) {
		if (hand == 0 && c < d[pt].x) {
			c = d[pt].x;
			continue;
		}

		while(pt <= n && c == d[pt].x) {
			s.insert(d[pt].y);
			hand += d[pt].y;
			++pt;
		}

		auto it = --s.end();
		hand -= *it; s.erase(it);
		ans += hand;
		++c;
	}

	cout << ans << endl;

	return 0;
}