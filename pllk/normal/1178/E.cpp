#include <iostream>
#include <algorithm>

using namespace std;

string s;
int n;

int main() {
	cin >> s;
	n = s.size();
	int a = 0;
	int b = n-1;
	string u;
	while (a+1 < b-1) {
		if (s[a] == s[b-1]) {
			u += s[a];
		} else if (s[a] == s[b]) {
			u += s[a];
		} else if (s[a+1] == s[b-1]) {
			u += s[a+1];
		} else if (s[a+1] == s[b]) {
			u += s[a+1];
		}
		a += 2; b -= 2;
	}
	string v = u;
	if (a <= b) u += s[a];
	reverse(v.begin(),v.end());
	cout << u << v << "\n";
}