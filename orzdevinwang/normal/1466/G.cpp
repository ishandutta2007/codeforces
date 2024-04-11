#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 2e6 + 7;
const int tN = 1e5 + 7;
const int mod = 1e9 + 7; 
const int p = 1019260817;
const int G = 19491001;
const int inv2 = (mod + 1) / 2;
int n, Q, has[N], Len, sPow[N];
void Init(string s) { Len = s.size(); L(i, 1, Len) has[i] = (has[i - 1] + 1ll * (s[i - 1] - 'a' + 1) * sPow[i] % p) % p; }
int d[tN];
string g[tN], s[23], ms, t, now;
int calc(int x) {
	int nowlen = g[x].size(), Hs = 0, res = 0;
	L(i, 1, nowlen) (Hs += 1ll * (g[x][i - 1] - 'a' + 1) * sPow[i] % p) %= p;
	L(i, 0, Len - nowlen) res += (has[i + nowlen] - has[i] + p) % p == 1ll * Hs * sPow[i] % p;
	return res;
}
int tmp, maxn;
int Pow[N], iPow[N], ans[tN];
int qz[tN][26];
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin >> n >> Q;
	cin >> s[0] >> t;
	Pow[0] = iPow[0] = sPow[0] = 1;
	L(i, 1, n) Pow[i] = Pow[i - 1] * 2 % mod, iPow[i] = 1ll * iPow[i - 1] * inv2 % mod;
	L(i, 1, 2000001) sPow[i] = 1ll * sPow[i - 1] * G % p;
	L(i, 1, Q) cin >> d[i] >> g[i], maxn = max(maxn, (int)g[i].size());
	now = s[0], Init(s[0]);
	L(i, 1, Q) (ans[i] += 1ll * Pow[d[i]] * calc(i) % mod) %= mod;
	int tmp = 0;
	while(1) {
		if((int)s[tmp].size() > maxn) break;
		L(i, 1, Q) if(d[i] > tmp) {
			ms.clear(); 
			int tlen = min((int)s[tmp].size(), (int)g[i].size() - 1);
			L(_i, (int)s[tmp].size() - tlen, (int)s[tmp].size() - 1) ms.push_back(s[tmp][_i]);
			ms.push_back(t[tmp]);
			L(_i, 0, tlen - 1) ms.push_back(s[tmp][_i]);
			Init(ms);
			(ans[i] += 1ll * Pow[d[i] - tmp - 1] % mod * calc(i) % mod) %= mod;
		}
		s[tmp + 1] = s[tmp] + t[tmp] + s[tmp], ++tmp; 
	}
	//  tmp 
	L(i, 1, n) {
		L(j, 0, 25) qz[i][j] = qz[i - 1][j];
		(qz[i][t[i - 1] - 'a'] += iPow[i]) %= mod;
	}
	int Len = now.size();
	L(i, 1, Q) {
		if(d[i] <= tmp) continue;
		int orz = g[i].size() - 1;
		L(j, 0, 25) { 
			ms.clear();
			L(_i, (int)s[tmp].size() - orz, (int)s[tmp].size() - 1) ms.push_back(s[tmp][_i]);
			ms.push_back(j + 'a');
			L(_i, 0, orz - 1) ms.push_back(s[tmp][_i]);
			Init(ms);
			(ans[i] += 1ll * (qz[d[i]][j] - qz[tmp][j] + mod) % mod * Pow[d[i]] % mod * calc(i) % mod) %= mod; 
		}
	}
	L(i, 1, Q) printf("%d\n", ans[i]); 
	return 0;
}