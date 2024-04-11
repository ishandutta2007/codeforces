#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
int n, a[N], qz[N];
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), qz[i] = qz[i - 1] + a[i];
	int maxn = qz[n];
	R(i, n - 1, 2) maxn = max(maxn, qz[i] - maxn);
	printf("%d\n", maxn);
	return 0;
}