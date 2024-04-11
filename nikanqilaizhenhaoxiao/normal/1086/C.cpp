#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int maxn = 1e6 + 10;

char s[maxn], a[maxn], b[maxn];

int main() {
	auto solve = [&]() {
		int k;
		scanf("%d", &k);
		scanf("%s", s);
		scanf("%s", a);
		scanf("%s", b);
		int n = strlen(s);
		static char match[255], m[255];
		static bool used[255], u[255];
		for (char c = 'a'; c <= 'z'; ++c) match[c] = 'A', used[c] = 0;
		char lst = k + 'a' - 1;
		auto OK = [&]() {
			puts("YES");
			for (char c = 'a'; c <= lst; ++c) {
				if(match[c] == 'A') {
					for (char d = 'a'; d <= lst; ++d) if(!used[d]) {
						used[d] = 1;
						putchar(d);
						break;
					}
				}
				else putchar(match[c]);
			}
			putchar('\n');
			return;
		};
		for (int i = 0; i < n; ++i) {
			if(a[i] == b[i]) {
				if(match[s[i]] == 'A') {
					if(used[a[i]]) { puts("NO"); return; }
					match[s[i]] = a[i], used[a[i]] = 1;
				}
				else if(match[s[i]] != a[i]) { puts("NO"); return; }
				continue;
			}
			if(match[s[i]] != 'A') {
				if(match[s[i]] < a[i] || match[s[i]] > b[i]) { puts("NO"); return; }
				if(match[s[i]] == a[i]) {
					for (++i; i < n; ++i) {
						if(match[s[i]] == 'A') {
							for (char c = lst; c >= 'a'; --c) if(!used[c]) {
								match[s[i]] = c;
								used[c] = 1;
								break;
							}
							if(match[s[i]] == 'A') { puts("NO"); return; }
						}
						if(match[s[i]] < a[i]) { puts("NO"); return; }
						if(match[s[i]] > a[i]) return OK();
					}
					return OK();
				}
				if(match[s[i]] == b[i]) {
					for (++i; i < n; ++i) {
						if(match[s[i]] == 'A') {
							for (char c = 'a'; c <= lst; ++c) if(!used[c]) {
								match[s[i]] = c;
								used[c] = 1;
								break;
							}
							if(match[s[i]] == 'A') { puts("NO"); return; }
						}
						if(match[s[i]] > b[i]) { puts("NO"); return; }
						if(match[s[i]] < b[i]) return OK();
					}
					return OK();
				}
				return OK();
			}
			for (char fuck = a[i]; fuck <= b[i]; ++fuck) if(!used[fuck]) {
				for (char c = 'a'; c <= lst; ++c) m[c] = match[c], u[c] = used[c];
				u[fuck] = 1;
				m[s[i]] = fuck;
				bool flag = 1;
				if(m[s[i]] == a[i]) {
					int I = i;
					for (++I; I < n; ++I) {
						if(m[s[I]] == 'A') {
							for (char c = lst; c >= 'a'; --c) if(!u[c]) {
								m[s[I]] = c;
								u[c] = 1;
								break;
							}
							if(m[s[I]] == 'A') { flag = 0; break; }
						}
						if(m[s[I]] < a[I]) { flag = 0; break; }
						if(m[s[I]] > a[I]) {
							for (char c = 'a'; c <= lst; ++c) match[c] = m[c], used[c] = u[c];
							return OK();
						}
					}
					if(!flag) continue;
					for (char c = 'a'; c <= lst; ++c) match[c] = m[c], used[c] = u[c];
					return OK();
				}
				if(m[s[i]] == b[i]) {
					int I = i;
					for (++I; I < n; ++I) {
						if(m[s[I]] == 'A') {
							for (char c = 'a'; c <= lst; ++c) if(!u[c]) {
								m[s[I]] = c;
								u[c] = 1;
								break;
							}
							if(m[s[I]] == 'A') { flag = 0; break; }
						}
						if(m[s[I]] > b[I]) { flag = 0; break; }
						if(m[s[I]] < b[I]) {
							for (char c = 'a'; c <= lst; ++c) match[c] = m[c], used[c] = u[c];
							return OK();
						}
					}
					if(!flag) continue;
					for (char c = 'a'; c <= lst; ++c) match[c] = m[c], used[c] = u[c];
					return OK();
				}
				for (char c = 'a'; c <= lst; ++c) match[c] = m[c], used[c] = u[c];
				return OK();
			}
			puts("NO");
			return;
		}
		return OK();
	};
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}