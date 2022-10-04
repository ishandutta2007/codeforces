#include <cstdio>
#include <cstring>
#include <algorithm>

int Type[256];
char str[15];

int main() {
	Type['B'] = 1;
	Type['C'] = 1;
	Type['D'] = 1;
	Type['G'] = 1;
	Type['J'] = 1;
	Type['O'] = 1;
	Type['P'] = 1;
	Type['Q'] = 1;
	Type['R'] = 1;
	Type['S'] = 1;
	Type['U'] = 1;
	scanf("%s", str);
	for (int i = 1; str[i]; ++i)
		if (Type[str[i]] != Type[*str])
			return puts("NO"), 0;
	puts("YES");
	return 0;
}