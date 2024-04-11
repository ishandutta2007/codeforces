#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
char s[maxn + 10];
int n;
vector<int> fir, las;

void solve(int p) {
	if (p == n + 1) return;
	if (s[p] == 'l') {
		solve(p + 1); printf("%d\n", p);
	} else {
		printf("%d\n", p); solve(p + 1);
	}
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	solve(1);
}