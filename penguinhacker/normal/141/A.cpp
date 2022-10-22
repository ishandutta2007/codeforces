#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s1, s2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1;
	cin >> s2;
	s1+=s2;
	cin >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1==s2) cout << "YES";
	else cout << "NO";
	return 0;
}