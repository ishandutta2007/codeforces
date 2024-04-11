#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	string s1 = "";
	string p = "a";
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		p[0] = s[i];
		if (p != "a") {
			s1 += p;
		} else {
			cnt++;
		}
	}
	string s2 = s1.substr(0, (s1.size()) / 2);
	if (s2 + s2 == s1 && s2 == s.substr(s.size() - s2.size(), s2.size())) {
		cout << s.substr(0, s.size() - (s1.size() / 2));
	} else {
		cout << ":(";
	}
}