#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define db double
using namespace std;
const int N = 1e6 + 7;
int n, m, cnt;
ll sum, a[N], b[N]; 
bool check(ll x) {
	priority_queue<pii> q;
	cnt = 0, sum = 0;
	L(i, 1, n) {
		q.push(mkp(-a[i] + x, 1));
		if(b[i] - q.top().first < 0) cnt += q.top().second, sum += b[i] - q.top().first, q.pop(), q.push(mkp(b[i], 0));
	}
	return cnt <= m;
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%lld", &a[i]);
	L(i, 1, n) scanf("%lld", &b[i]);
	ll l = 0, r = 2e9, ans = 0;
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(check(mid)) ans = sum + m * mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}