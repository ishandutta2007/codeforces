#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[50000];

bool cmp (string x, string y) {
	return x + y < y + x;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; i++) cin >> s[i];
	
	sort (s, s + n, cmp);
	
	for (int i=0; i<n; i++) cout << s[i];
	cout << endl;
	
	return 0;
}