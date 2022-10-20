#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int cnt[30];
int n;
char s[N], t[N];
int id[N];

void solve(int a, int b, int c) {
	char foo = s[a + b + 1];
	for (int i = a + b + 1; i > a + 1; i--) {
		s[i] = s[i - 1];
	}
	s[a + 1] = foo;
	reverse(s + 1, s + a + 1);
	reverse(s + a + 2, s + a + b + 2);
	reverse(s + a + b + 2, s + a + b + c + 2);
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for (int i = 1; i <= n; i++) {
		cnt[s[i] - 'a']--;
		cnt[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			puts("-1");
			return 0;
		}
	}
	int l = 1, r = n;
	for (int i = n; i; i--) {
		if ((n - i) % 2 == 0) {
			id[i] = r--;
		} else {
			id[i] = l++;
		}
	}
	printf("%d\n", n * 3);
	for (int i = 1; i <= n; i++) {
		int pos = -1;
		for (int j = i; j <= n; j++) {
			if (t[id[i]] == s[j]) {
				pos = j;
				break;
			}
		}
		int a, b, c;
		a = i - 1;
		b = pos - a - 1;
		c = n - pos;
		printf("%d %d %d ", c + 1, b, a + 1);
		solve(a, b, c);
	}
	return 0;
}