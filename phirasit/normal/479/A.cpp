#include <stdio.h>
#include <algorithm>

using namespace std;

int a, b, c;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", max(a*b*c, max((a+b)*c, max(a*(b+c), max(a+b+c, max(a*b+c, a+b*c))))));
	return 0;
}