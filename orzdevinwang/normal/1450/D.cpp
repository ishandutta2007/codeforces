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
int n, m, a[N], mp[N], cnt[N];
void Main() {
	scanf("%d", &n);
	L(i, 1, n) mp[i] = cnt[i] = 0;
	int ok = 1, maxn = 2;
	L(i, 1, n) {
		scanf("%d", &a[i]), cnt[a[i]] ++;
		if(mp[a[i]]) maxn = max(maxn, i - mp[a[i]] + 1);
		else mp[a[i]] = i;
	}
	L(i, 1, n) if(!mp[i]) ok = 0, maxn = max(maxn, n - i + 2);
	printf("%d", ok);
	int l = 1, r = n, qwq = 0;
	L(i, 1, n) {
		if(cnt[i] > 1) break;
		if(a[l] == i) ++l, qwq ++;
		else if(a[r] == i) --r, qwq ++;
		else break;
	}
	maxn = max(maxn, n - qwq);
	L(i, 2, maxn - 1) printf("0");
	L(i, maxn, n) printf("1");
	puts("");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}