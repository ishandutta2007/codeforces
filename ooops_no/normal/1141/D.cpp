/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	map<char, int> m;
	vector<int> v[27], v1, v2;
	cin >> s;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		m[a]++;
		if (a != '?') {
			v[(int)a - 96].pb(i + 1);
		}
		else {
			v1.pb(i + 1);
		}
	}
	int cnt = 0;
	vector < pair < int, int > > g;
	for (int i = 0; i < n; i++) {
		char a = s[i];
		if (a == '?') {
			v2.pb(i + 1);
			cnt++;
			continue;
		}
		if (m[a] != 0) {
			cnt++;
			m[a]--;
			g.pb(mp(i + 1, v[(int)a - 96][m[a]]));
		}
		else {
			if (m['?'] != 0) {
				m['?']--;
				g.pb(mp(i + 1, v1[m['?']]));
			}
		}
	}
	for (auto to : v2) {
		bool x = 1;
		for (int i = 97; i <= 122; i++) {
			if (m[i] != 0) {
				m[i]--;
				g.pb(mp(to, v[i - 96][m[i]]));
				x = 0;
				break;
			}
		}
		if (x) {
			m['?']--;
			g.pb(mp(to, v1[m['?']]));
		}
	}
	cout << g.size() << endl;
	for (auto to : g) {
		cout << to.first << " " << to.second << endl;
	}
}