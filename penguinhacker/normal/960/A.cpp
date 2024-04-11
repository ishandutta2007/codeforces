#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	string t=s;
	sort(t.begin(), t.end());
	if (s!=t) {
		cout << "NO";
		return 0;
	}
	int a=count(s.begin(), s.end(), 'a');
	int b=count(s.begin(), s.end(), 'b');
	int c=count(s.begin(), s.end(), 'c');
	cout << (a&&b&&(a==c||b==c)?"YES":"NO");
	return 0;
}