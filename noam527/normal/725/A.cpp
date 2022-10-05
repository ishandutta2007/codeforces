#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, ans = 0, i = 0;
	string s;
	cin >> n >> s;
	while (i < n && s[i] == '<') ans++, i++;
	i = n - 1;
	while (i >= 0 && s[i] == '>') ans++, i--;
	cout << ans << endl;
}