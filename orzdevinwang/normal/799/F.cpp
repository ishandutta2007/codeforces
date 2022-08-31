#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define se second
#define fi first
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 7;
const ull mod = 2e18 + 7;
int n, m;
ull st[N], en[N], p[N];
ull getrand() {
	ull x = 1, res = 0, G = RAND_MAX;
	res += x * rand(), x *= G;
	res += x * rand(), x *= G;
	res += x * rand(), x *= G;
	res += x * rand(), x *= G;
	return res;
}
ll ans;
map<ull, ll> gs, mp; 
int main() {
	srand(114514 + 1919810 + 19260817);
	scanf("%d%d", &n, &m);
	ull All = 0;
	L(i, 1, n) {
		int l, r; scanf("%d%d", &l, &r);
		ull ff = getrand();
		All ^= ff, p[l] ^= ff, p[r + 1] ^= ff, st[l] ^= ff, en[r] ^= ff;
	}
	ull isL = 0, isR = All, now = 0, sum = 0; ll resa = 0, resb = 0;
	L(i, 1, m) {
		isL ^= en[i - 1], mp[sum ^ isL] += i, gs[sum ^ isL]++;
		now ^= p[i], sum ^= now, isR ^= st[i]; 
		if(now) resa = gs[sum ^ isR ^ All], resb = mp[sum ^ isR ^ All];
		ans += resa * (i + 1) - resb;
	}
	printf("%lld\n", ans);
	return 0;
}