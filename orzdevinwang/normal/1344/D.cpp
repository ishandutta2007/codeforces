// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
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
int n;
ll k, a[N], d[N];
ll get(int x, ll y) {
	ll l = 0, r = a[x], ans = 0;
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(a[x] - 3 * (mid - 1) * (mid - 1) - 3 * (mid - 1) + 1 >= y) ans = mid, l = mid + 1; //  mid
		else r = mid - 1;
	}
	return ans;
}
bool check(ll x) {
	ll sum = 0;
	L(i, 1, n) sum += get(i, x);
	return sum <= k;
}
priority_queue< pair<ll, int> > q;
void Brute() {
	L(i, 1, n) {
		if(d[i] == a[i]) continue;
		q.push(mkp(a[i] - 3 * d[i] * d[i] - 3 * d[i] + 1, i));
	}
	L(t, 1, k) {
		int P = q.top().second;
		q.pop();
		d[P] ++;
		if(d[P] == a[P]) continue;
		q.push(mkp(a[P] - 3 * d[P] * d[P] - 3 * d[P] + 1, P));
	}
}
int main() {
	scanf("%d%lld", &n, &k);
	L(i, 1, n) scanf("%lld", &a[i]);
	ll l = - 3e18 - 1e12, r = 1e9 + 7, ans;
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	} 
	L(i, 1, n) d[i] = get(i, ans), k -= d[i];
	if(k > n) assert(0);
	Brute();
	ll sum = 0;
	L(i, 1, n) printf("%lld ", d[i]), sum += d[i] * (a[i] - d[i] * d[i]);
	puts("");
	// cout << sum << endl;
	return 0;
}