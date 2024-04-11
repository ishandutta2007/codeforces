#include <cstdio>

int const N = 222;

int next[N];
bool was[N];
bool slave[N];
char s[N];

int main() {
	int n;
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) {
		gets(s);
		for (int i = 0; s[i]; ++i) {
			was[s[i]] = true;
			if (s[i + 1]) {
				next[s[i]] = s[i + 1];
				slave[s[i + 1]] = true;
			}
		}
	}
	int size = 0;
	for (char x = 'a'; x <= 'z'; ++x) {
		if (was[x] && !slave[x]) {
			for (char v = x; v; v = next[v]) {
				s[size++] = v;
			}
		}
	}
	s[size] = 9;
	puts(s);
}