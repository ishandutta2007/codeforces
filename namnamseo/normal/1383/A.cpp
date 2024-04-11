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
char a[100010];
char b[100010];

set<pair<char,char>> s;

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n >>	a >> b;
	bool err = 0;
	s.clear();
	rep(i, n) {
		if (b[i] < a[i]) {
			cout << "-1\n";
			err = 1;
			break;
		}
		if (b[i] != a[i]) s.insert(make_pair(b[i], a[i]));
	}
	if (err) continue;

	int ans = 0;
	while (s.size()) {
		++ans;
		vector<pair<char,char>> v;
		char x = s.begin()->y;
		auto z = *s.begin();
		for (auto tmp:s) if (tmp.y == x) v.pb(tmp);
		for (auto x:v) s.erase(x);
		for (auto t:v) {
			if (t.x != z.x)
				s.emplace(t.x, z.x);
		}
	}

	cout << ans << '\n';
}
	return 0;
}