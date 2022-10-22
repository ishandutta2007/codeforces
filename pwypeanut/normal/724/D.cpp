#include <bits/stdc++.h>
using namespace std;

int M, cnt[26];
string S;
vector<int> v;

int main() {
	cin >> M >> S;
	for (int i = 0; i < S.length(); i++) cnt[S[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		v.clear();
		v.push_back(-1);
		for (int j = 0; j < S.length(); j++) if (S[j] - 'a' <= i) v.push_back(j);
		v.push_back(S.length());
		bool fail = 0;
		for (int j = 0; j < (int)v.size() - 1; j++) if (v[j + 1] - v[j] > M) fail = 1;
		if (!fail) {
			int last = -1, lastavail = -1, cur = 0;
			for (int j = 0; j < S.length(); j++) {
				if (S[j] - 'a' < i) last = j;
				if (S[j] - 'a' == i) lastavail = j;
				if (j - last == M) {
					last = lastavail;
					cur++;
				}
			}
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < cnt[j]; k++) printf("%c", 'a' + j);
				
			}
			for (int k = 0; k < cur; k++) printf("%c", 'a' + i);
			printf("\n");
			return 0;
		}
	}
}