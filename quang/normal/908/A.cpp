#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int res = 0;
	for (char u : s) {
		if (u == 'a' || u == 'e' || u == 'i' || u == 'o' || u == 'u') {
			res++;
		}
		if (u == '1' || u == '3' || u == '5' || u == '7' || u == '9') {
			res++;
		}
	}	
	cout << res << endl;
	return 0;
}