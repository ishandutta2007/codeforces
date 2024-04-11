#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, x[N], y[N], a[N], b[N];
ll sumx, sumy;
void Main() {
	scanf("%d", &n);
	L(i, 1, n) {
		scanf("%d%d", &x[i], &y[i]);
		sumx += x[i];
		sumy += y[i];
	}
	L(i, 1, n) {
		scanf("%d%d", &a[i], &b[i]);
		sumx += a[i];
		sumy += b[i];
	}
	printf("%lld %lld\n", sumx / n, sumy / n);
}
int main() {
	Main();
	return 0;
}