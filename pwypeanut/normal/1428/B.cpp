#include <bits/stdc++.h>
using namespace std;

int TC, N;
char S[300005];

int main() {
	scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		scanf(" %s", S);
		int ans = 0;
		bool l = 0, r = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == '-' || S[(i + (N - 1)) % N] == '-') ans++;
			if (S[i] == '<') l = 1;
			if (S[i] == '>') r = 1;
		}
		if (l == 1 && r == 1) printf("%d\n", ans);
		else printf("%d\n", N);
	}
}