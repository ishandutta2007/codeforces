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
int n, a[N], cnt[N], zs, ans;
int fir[N << 1];
void work(int x) {
	int now = N;
	memset(fir, -1, sizeof(fir));
	fir[now] = 0;
	L(i, 1, n) {
		if(a[i] == zs) now ++;
		else if(a[i] == x) now --;
		if(fir[now] == -1) fir[now] = i;
		else ans = max(ans, i - fir[now]);
	}
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), cnt[a[i]] ++;
	L(i, 1, n) if(cnt[i] > cnt[zs]) zs = i;
	L(i, 1, min(n, 100)) if(i != zs) work(i); 
	printf("%d\n", ans);
	return 0;
}