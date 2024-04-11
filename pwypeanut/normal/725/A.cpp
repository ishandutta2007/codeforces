#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main() {
	scanf("%d", &N);
	cin >> S;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '<') ans++;
		else break;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == '>') ans++;
		else break;
	}
	printf("%d\n", ans);
}