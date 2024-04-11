#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s, hello="hello";
int state=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (char c : s) {
		if (c==hello[state]) state++;
		if (state==5) break;
	}
	if (state==5) cout << "YES";
	else cout << "NO";
	return 0;
}