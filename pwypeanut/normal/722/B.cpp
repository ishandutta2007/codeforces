#include <bits/stdc++.h>
using namespace std;

int N, a[105];

int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	scanf("\n");
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y') a[i]--;
		}
	}
	for (int i = 0; i < N; i++) {
		if (a[i] != 0) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}