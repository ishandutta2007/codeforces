#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, tc;
string s[1505];
map<string, int> m;

int conv(char c) {
	if (c == 'S') return 1;
	else if (c == 'E') return 2;
	else return 3;
}

main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string yeet;
			for (int l = 0; l < k; l++) {
				if (s[i][l] == s[j][l]) yeet.push_back(conv(s[i][l]));
				else {
					char arr[] = {'S', 'E', 'T'};
					for (char c : arr) {
						if (s[i][l] != c && s[j][l] != c) {
							yeet.push_back(conv(c));
							break;
						}
					}
				}
			}
			tc += m[yeet];
		}
		string tmp;
		for (int j = 0; j < k; j++)
			tmp.push_back(conv(s[i][j]));
		m[tmp]++;
	}
	cout << tc << '\n';
}