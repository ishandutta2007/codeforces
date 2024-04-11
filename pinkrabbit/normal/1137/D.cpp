#include <cstdio>
// luogu y'no?
int t;
inline void gett() {
	fflush(stdout);
	scanf("%d", &t);
	for (int x = t; x; --x) scanf("%*s");
}

int main() {
	do {
		puts("next 0 1"), gett();
		puts("next 0"), gett();
	} while (t == 3);
	do {
		puts("next 0 1 2 3 4 5 6 7 8 9"), gett();
	} while (t == 2);
	puts("done");
	return 0;
}