#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string s;
int n, m, q;
char c;

int FindBest(char a, int mx) {
	int l = 0, r = 0, cnt = 0, maxfound = 0;
	if (s[0] != a) cnt++;
	while (r < n) {
		if (cnt <= mx)
			maxfound = max(maxfound, r - l + 1);
		if (cnt <= mx) {
			r++;
			if (s[r] != a)
				cnt++;
		}
		else {
			l++;
			if (s[l - 1] != a)
				cnt--;
		}
	}
	return maxfound;
}

int main() {
	cin >> n >> s;
	int table[26][1500];
	for (int i = 0; i < 26; i++)
		for (int x = 0; x < n; x++)
			table[i][x] = FindBest((char)(i + 97), x + 1);
	cin >> q;
	for (int i = 0; i < q; i++)
		cin >> m >> c, cout << table[c - 'a'][m - 1] << endl;
}