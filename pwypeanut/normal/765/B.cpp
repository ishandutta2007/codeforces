#include <bits/stdc++.h>
using namespace std;

string S;
bool b[26];
int cnt = 0;

int main() {
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (b[S[i] - 'a']) continue;
		if (cnt != S[i] - 'a') {
			printf("NO\n");
			return 0;
		}
		b[S[i] - 'a'] = 1;
		cnt++;
	}
	printf("YES\n");
}