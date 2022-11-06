#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	int p = s.size();
	int y = 0;
	for (int i = 0; i < s.size(); ++i) 
		if (s[i] == 'a') y++;
	int r = s.size();
	p -= y;
	cout << r - max(p - (y - 1), 0);
}