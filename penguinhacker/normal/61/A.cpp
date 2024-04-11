#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s1, s2, ans="";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2;
	for (int i=0; i<s1.size(); ++i) {
		if (s1[i]==s2[i])
			ans+='0';
		else
			ans+='1';
	}
	cout << ans;
	return 0;
}