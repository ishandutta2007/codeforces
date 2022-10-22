#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int curr=1;
bool dang=0;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (int i=1; i<s.size(); ++i) {
		if (s[i]==s[i-1]) curr++;
		else curr=1;
		if (curr>=7) dang=1;
	}
	cout << (dang?"YES":"NO");
	return 0;
}