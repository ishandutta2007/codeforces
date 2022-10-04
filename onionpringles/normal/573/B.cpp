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

int h[100002];
int dist[1000002];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	nextInt(n);
	h[0] = 0;
	h[n + 1] = 0;
	F(i, n) {
		nextInt(h[i + 1]);
	}
	int curx = 0;
	int cury = 0;
	F(i, n + 1) {
		if (h[i] - i < cury - curx) {
			curx = i;
			cury = h[i];
		}
		dist[i] = cury + i - curx;
	}
	curx = n + 1;
	cury = 0;
	F(i, n + 1) {
		int j = n + 1 - i;
		if (h[j] + j < curx + cury) {
			curx = j;
			cury = h[j];
		}
		dist[j] = min(dist[j], curx - j + cury);
	}
	int _mx = -1;
	F(i, n) {
		_mx = max(_mx, dist[i + 1]);
	}
	printf("%d", _mx);
	return 0;
}