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
int GCD(int x, int y) { return y == 0 ? x : GCD(y, x % y); }
int n, m, maxn = 1e5; ll ans;
int f[N];
int mu[N], p[N], tot;
bool Prime[N];
void xxs() {
	mu[1] = 1;
	for(int i = 2; i <= maxn; i++) {
		if(!Prime[i]) p[++tot] = i, mu[i] = -1;
		for(int j = 1; p[j] * i <= maxn && j <= tot; j ++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) {
				mu[p[j] * i] = 0;
				break;
			}
			mu[p[j] * i] = -mu[i];
		}
	}
}
vector<int> ve[N];
int sum[N];
int get(int x) { // \sum_{i = 1} ^ n [gcd(i, x) = 1] f_i
	int res = 0;
	for(int t : ve[x]) res += mu[t] * sum[t];
	return res;
}
void add(int x, int val) { for(int t : ve[x]) sum[t] += val; }
stack<int> stk;
void work(int x) {
	R(i, maxn / x, 1) {
		if(!f[i * x]) continue;
		int hs = get(i);
		// cout << x << " " << i * x << " : " << hs << endl;
		if(!hs) {
			stk.push(i), add(i, 1);
			continue;
		}
		while(1) {
			if(GCD(i, stk.top()) == 1) hs --, ans = max(ans, 1ll * i * stk.top() * x);
			add(stk.top(), -1), stk.pop();
			if(!hs) break;
		}
	}
	while(!stk.empty()) add(stk.top(), -1), stk.pop();
}
int main() {
	int x;
	xxs();
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &x), f[x] = 1, ans = max(ans, (ll)x);
	L(i, 1, maxn) L(j, 1, maxn / i) ve[i * j].push_back(i);
	L(i, 1, maxn) work(i);
	printf("%lld\n", ans);
	return 0;
}