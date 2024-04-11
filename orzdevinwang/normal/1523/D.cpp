#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7;
int T, n, p, m, rns, pc[N], g[N], dp[N], tp;
ll ns, msk[N];
char s[N];
mt19937_64 orz((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
void Main() {
	cin >> n >> m >> p;
	L(i, 1, n) {
		cin >> (s + 1);
		L(j, 1, m) if(s[j] - '0') msk[i] |= (1LL << (j - 1));
	}
	L(i, 0, (1 << 15) - 1) pc[i] = pc[i >> 1] + (i & 1);
	L(test, 1, 30) {
		int o = orz() % n + 1;
		tp = 0;
		L(i, 0, m - 1) if(msk[o] >> i & 1) g[tp++] = i;
		L(i, 1, n) {
			int sm = 0;
			L(a, 0, tp - 1) if(msk[i] >> g[a] & 1) sm |= 1LL << a;
			dp[sm]++;
		}
		L(i, 0, tp - 1) L(j, 0, (1 << tp) - 1) if(!(j & (1 << i))) dp[j] += dp[j ^ (1 << i)];
		L(i, 0, (1 << tp) - 1) if(dp[i] >= (n + 1) / 2) {
			if(pc[i] > rns) {
				ns = 0, rns = pc[i];
				L(j, 0, tp - 1) if(i >> j & 1) ns |= (1LL << g[j]);
			}
		}
		L(j, 0, (1 << tp) - 1) dp[j] = 0; 
	}
	L(i, 0, m - 1) cout << (ns >> i & 1); 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Main();
	return 0;
}