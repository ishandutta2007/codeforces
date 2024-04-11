#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N], sum, ans;
int G[33];
void ins(int x) {
	R(i, 30, 0) if((x >> i) & 1) {
		if(!G[i]) G[i] = x, ans ++;
		x ^= G[i];
	}
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), sum ^= a[i];
	if(sum == 0) return puts("-1"), 0;
	ins(sum), sum = 0;
	L(i, 1, n - 1) sum ^= a[i], ins(sum);
	printf("%d\n", ans);
	return 0;
}