#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	char arr[] = { '8', '#', '#', '3', '6', '9', '4', '7', '0', '5' };
	string s;
	cin >> s;
	for (int i = 0, j = s.size() - 1; i < s.size(); ++i, --j) 
		if (s[i] != arr[s[j] - '0']) {
			cout << "No";
			return 0;
		}
	cout << "Yes";
	return 0;
}