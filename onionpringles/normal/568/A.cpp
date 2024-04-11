#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair((a),(b))
#define nextInt(n) scanf("%d",&(n))
#define F(i,n) for(int (i) = 0; (i) < n; (i)++)

using namespace std;

const int MN = 10000001;

int pr[MN];
int pal[MN];

int ispal(int n) {
	int tmp[20];
	int p = 0;
	while (n) {
		tmp[p++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < p / 2; i++) {
		if (tmp[i] != tmp[p - 1 - i]) return 0;
	}
	return 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < MN; i++) pal[i] = ispal(i);
	for (int i = 2; i < MN; i++) pal[i] += pal[i - 1];
	for (int i = 2; i < MN; i++) pr[i] = 1;
	for (int i = 2; i < MN; i++) {
		if (!pr[i]) continue;
		for (int j = 2 * i; j < MN; j += i) {
			pr[j] = 0;
		}
	}
	for (int i = 2; i < MN; i++) pr[i] += pr[i - 1];
	int maxval = -1;
	int p, q;
	nextInt(p); nextInt(q);
	for (int i = 1; i < MN; i++) {
		if ((long long)q*pr[i] <= (long long)p*pal[i]) {
			maxval = i;
		}
	}
	printf("%d\n", maxval);
	return 0;
}