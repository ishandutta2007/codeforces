#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, num;
string s;
set<char> p;
map<char, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (char c : s)
		p.insert(c);
	num = p.size();
	
	mp[s[0]]++;
	int lb = 0;
	int rb = 0;
	int best = 1e9;
	while (rb < n) {
		if (mp.size() == num) {
			best = min(best, rb-lb+1);
			mp[s[lb]]--;
			if (mp[s[lb]] == 0)
				mp.erase(s[lb]);
			lb++;
		}
		else {
			rb++;
			mp[s[rb]]++;
		}
	}
	
	cout << best;
	return 0;
}