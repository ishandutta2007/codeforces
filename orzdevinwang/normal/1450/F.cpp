#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, a[N], sum, f[N], tot, cnt[N], zs, cnta, cntb;
void Main() {
	tot = 0;
	scanf("%d", &n);
	L(i, 1, n) cnt[i] = 0;
	L(i, 1, n) {
		scanf("%d", &a[i]), cnt[a[i]] ++;
		if(a[i] == a[i - 1]) f[++tot] = i - 1;
	}
	f[++tot] = n;
	L(i, 1, n) if(cnt[i] > (n + 1) / 2) return printf("-1\n"), void();
	L(i, 1, n) cnt[i] = 0;
	cnta = cntb = zs = 0;
	L(i, 1, tot) cnt[a[f[i - 1] + 1]] ++, cnt[a[f[i]]] ++;
	L(i, 1, n) if(cnt[i] > cnt[zs]) zs = i;
	if(cnt[zs] <= tot + 1) printf("%d\n", tot - 1);
	else printf("%d\n", cnt[zs] - 2);
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}