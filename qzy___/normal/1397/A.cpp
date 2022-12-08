#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

int T;
int n, cnt[26];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 26; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); j++) cnt[s[j] - 'a']++;
		}
		int flag = 0;
		for (int i = 0; i < 26; i++) if (cnt[i] % n) flag = 1;
		if (!flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}