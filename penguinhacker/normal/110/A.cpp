#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	cin >> s;
	for (char c : s)
		if (c=='4'||c=='7')
			cnt++;
	if (cnt==4||cnt==7)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}