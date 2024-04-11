#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, b;
	scanf("%d %d", &a, &b);
	if (b > a) {
		puts("-1");
		return 0;
	}
	int c = a / b;
	if (c % 2 == 0) {
		c--;
	}
	double res = (double)(a + b) / (c + 1);
	printf("%.15f", res);
	return 0;
}