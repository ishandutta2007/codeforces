#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair(a,b)
#define F(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define nextInt(n) scanf("%d", &(n))

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int a[100000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	nextInt(n);
	F(i, n) {
		nextInt(a[i]);
	}
	F(i, n - 1) {
		int g = gcd(a[i], a[i + 1]);
		int x = a[i] / g;
		int y = a[i + 1] / g;
		while (x % 2 == 0) x /= 2;
		while (x % 3 == 0) x /= 3;
		while (y % 2 == 0) y /= 2;
		while (y % 3 == 0) y /= 3;
		if (x > 1 || y > 1) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}