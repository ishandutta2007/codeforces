#include <cstdio>

bool hit[4] = {0};
int p[4];

int main () {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			int a;
			scanf ("%d", &a);
			hit[i] |= a;
			hit[(i + 4 - 1 - j) % 4] |= a;
		}
		scanf ("%d", &p[i]);
	}
	for (int i = 0; i < 4; i++)
		if (hit[i] && p[i]) {
			puts ("YES");
			return 0;
		}
	puts ("NO");
	return 0;
}