#include <bits/stdc++.h>
using namespace std;

int N, cur;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int t;
		string s;
		cin >> t >> s;
		if (s == "East" || s == "West") {
			if (cur == 0 || cur == 20000) {
				printf("NO\n");
				return 0;
			}
		}
		if (s == "North") {
			if (cur < t) {
				printf("NO\n");
				return 0;
			} else cur -= t;
		}
		if (s == "South") {
			if (cur + t > 20000) {
				printf("NO\n");
				return 0;
			} else cur += t;
		}
	}
	if (cur == 0) printf("YES\n");
	else printf("NO\n");
}