//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	set<int> pos[26];
	for (int i = 0; i < sz(s); i++)
		pos[s[i] - 'a'].insert(i);
	for (int i = 0; i < 26; i++)
		pos[i].insert(sz(s));
	int q;
	cin >> q;
	while (q--) {
		int ty, fi, se;
		char th;
		cin >> ty >> fi;
		fi--;
		if (ty == 1) {
			cin >> th;
			pos[s[fi] - 'a'].erase(fi);
			s[fi] = th;
			pos[s[fi] - 'a'].insert(fi);
		}
		else {
			cin >> se;
			int ans = 0;
			for (int i = 0; i < 26; i++)
				ans += *pos[i].lower_bound(fi) < se;
			cout << ans << '\n';
		}
	}
	return 0;
}