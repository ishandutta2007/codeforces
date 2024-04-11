#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[100];
int play[40000];
int len;
int play399;
int play400;
int seq[40000];

int bs(int val, int len) {
	int l = 0; int  u = len;
	while (l != u) {
		int mid = (l + u) / 2;
		if (seq[mid] > val) {
			u = mid;
		}
		else l = mid + 1;
	}
	return u;
}

int lis(int n) {
	len = 0;
	for (int i = 0; i < n; i++) {
		int val = play[i];
		int bb = bs(val, len);
		if (bb == len) {
			seq[len++] = val;
		}
		else {
			seq[bb] = val;
		}
	}
	return len;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	setbuf(stdout, NULL);
	int n, T;
	scanf("%d %d", &n, &T);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < 400*n; i++) {
		play[i] = a[i%n];
	}
	if (T <= 400) {
		printf("%d\n", lis(T*n));
	}
	else {
		play399 = lis(n * 399);
		play400 = lis(n * 400);
		int dif = play400 - play399;
		printf("%d\n", play400 + dif*(T - 400));
	}
	return 0;
}