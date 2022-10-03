#include <cstdio>
#include <cstring>

char str[100];
 
int main() {
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 2; i < len; ++i)
		if ((str[i] - 'A') != ((str[i - 2] - 'A') + (str[i - 1] - 'A')) % 26)
			return puts("NO"), 0;
	puts("YES");
	return 0;
}