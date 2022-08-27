#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int S = 5e5 + 7, N = 1 << 24, M = 1e7, mod = 1e9 + 7;
int n, pw[S], cnt[N], g[N];
bool Prime[N];
int p[N >> 3], tot;
void xxs(int x) {
    L(i, 2, x) {
        if(!Prime[i]) p[++tot] = i;
        for(int j = 1; j <= tot && p[j] * i <= x; j++) {
            Prime[p[j] * i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	xxs (M);
	cin >> n;
	L(i, 1, n) {
		int a;
		cin >> a;
		cnt[a] += 1;
	}
	pw[0] = 1;
	L(i, 1, n) pw[i] = (ll) pw[i - 1] * 2 % mod;
	L(i, 1, tot) 
		R(j, M / p[i], 1) 
			cnt[j] += cnt[j * p[i]];
	L(i, 1, M) 
		g[i] = cnt[i], cnt[i] = pw[cnt[i]] - 1;
	L(i, 1, tot) 
		L(j, 1, M / p[i]) 
			(cnt[j] += mod - cnt[j * p[i]]) %= mod;
	cnt[1] = 0;
	L(i, 1, tot) 
		R(j, M / p[i], 1) 
			(cnt[j] += cnt[j * p[i]]) %= mod;
	// L(i, 1, 10) cout << cnt[i] << ' ';
	// cout << '\n';
	// L(i, 1, 10) cout << g[i] << ' ';
	// cout << '\n';
	L(i, 1, M) 
		cnt[i] = (ll) cnt[i] * g[i] % mod;
	L(i, 1, tot) 
		L(j, 1, M / p[i]) 
			(cnt[j] += mod - cnt[j * p[i]]) %= mod;
	cout << cnt[1] << '\n';
	return 0;
}