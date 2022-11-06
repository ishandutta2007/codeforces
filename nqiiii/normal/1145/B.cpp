#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main() {
	scanf("%d", &n);
	int w = n % 10;
	if (w == 1 || w == 7 || w == 9) puts("NO");
	else if (n == 12) puts("YES");
	else if (n >= 10 && n <= 29) puts("NO");
	else if (n >= 70 && n <= 79) puts("NO");
	else if (n >= 90) puts("NO");
	else puts("YES");
}