#include"bits/stdc++.h"
using namespace std;


string s;
vector<string> v;
int main() {
	cin >> s;
	for (int i = 0; i < 5; i++) {
		string a;
		cin >> a;
		if (s[0] == a[0]) {
			puts("YES");
			return 0;
		}
		if (s[1] == a[1]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}