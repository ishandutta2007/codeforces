#include <stdio.h>
#include <algorithm>
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", std::min(a, std::min(b / 2, c / 4)) * 7);
	return 0;
}