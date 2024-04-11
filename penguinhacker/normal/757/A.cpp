#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int cnt[256];
// "Bulbasaur";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for (char c : s)
		++cnt[c];
	cout << min({cnt['u']/2, cnt['l'], cnt['s'], cnt['r'], cnt['a']/2, cnt['B'], cnt['b']});
	return 0;
}