#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
int n, k, a[N];
ll now, ans;
priority_queue<ll> q;
int main() {
	scanf("%d%d", &n, &k);
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, k + 1) q.push(0);
	sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
	L(i, 1, n) {
		ll sum = q.top();
		q.pop();
		ans += sum;
		q.push(sum + a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}