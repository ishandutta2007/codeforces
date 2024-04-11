#include <bits/stdc++.h>
using namespace std;

string s[20];
int id[20];
multiset <string> all;

bool cmp(int x, int y) {
	return s[x] < s[y];
}

int main () {
	int T; cin >> T;
	while (T--) {
		all.clear();
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			id[i] = i;
			all.insert(s[i]);
		}
		sort(id, id + n, cmp);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int nxt = i;
			while (nxt < n && s[id[nxt]] == s[id[i]]) nxt++;
			for (int j = i + 1; j < nxt; j++) {
				int x = id[j];
				all.erase(all.find(s[x])), ans++;
				for (int k = 0; k < 4; k++) {
					for (char p = '0'; p < '9'; p++) {
						if (s[x][k] == p) continue;
						char old = s[x][k];
						s[x][k] = p;
						if (!all.count(s[x])) {
							all.insert(s[x]);
							goto END;
						}
						s[x][k] = old;
					}
				}
				END:;
			}
			i = nxt - 1;
		}
		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			cout << s[i] << endl;
		}
	}
	return 0;
}