#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s, temp="", ans="";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (char c:s)
		if (c!='a'&&c!='e'&&c!='o'&&c!='u'&&c!='y'&&c!='i')
			temp+=c;
	for (char c:temp) {
		ans+='.'; ans+=c;
	}
	cout << ans;
	return 0;
}