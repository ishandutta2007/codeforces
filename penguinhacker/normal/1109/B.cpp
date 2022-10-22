#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool pal(string s) {
	int n = s.size();
	for (int i = 0; i < n / 2; ++i) if (s[i] != s[n - i - 1]) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	for (int i = 1; i < n; ++i)
		if (pal(s.substr(i) + s.substr(0, i)) && s != s.substr(i) + s.substr(0, i))
			{cout << 1; return 0;}
	for (int i = 1; i < n / 2; ++i)
		if (s[i] != s[i - 1])
			{cout << 2; return 0;}
	cout << "Impossible";
	return 0;
}