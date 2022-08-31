#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, a[N], pre[N], suf[N], S, G, cnt = 2;
void GCD(vi S, bool rev) { // min-max  gcd
	L(i, 1, (1 << sz(S)) - 1) {
		int bt = __builtin_popcount(i);
		cout << (bt & 1 ? rev : rev ^ 1) << ' ' << bt << ' ';
		L(k, 0, sz(S) - 1) if(i >> k & 1) cout << S[k] << ' ';
		cout << '\n';
	}
}
vi get(int x, int G) { //  <= 9  gcd 
	int tG = a[x % n + 1];
	vi ns = {x % n + 1};
	L(o, 2, tG) if(tG % o == 0) {
		int prd = 1, xprd = 1;
		while(G % o == 0) G /= o, prd *= o;
		while(tG % o == 0) tG /= o, xprd *= o;
		if(prd == xprd) continue ;
		L(i, 1, n) if(i != x && (a[i] / prd) % o) {
			ns.emplace_back(i), tG = __gcd(tG, a[i]);
			break ;
		}
		if(o < tG && o > tG / o) o = tG - 1;
	}
	return sort(ns.begin(), ns.end()), assert(G == tG), ns;
} 
vi pf[N], u;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], pre[i] = __gcd(pre[i - 1], a[i]);
	R(i, n, 1) suf[i] = __gcd(suf[i + 1], a[i]);
	G = pre[n], u = get(0, G);
	L(i, 1, n) if(__gcd(pre[i - 1], suf[i + 1]) != G) pf[i] = get(i, __gcd(pre[i - 1], suf[i + 1])), S += (1 << sz(pf[i])) - 1, --cnt;
	cout << S + abs(cnt) * ((1 << sz(u)) - 1) << '\n';
	if(cnt > 0) L(i, 1, cnt) GCD(u, 0);	
	else L(i, 1, -cnt) GCD(u, 1);
	L(i, 1, n) if(sz(pf[i])) GCD(pf[i], 0);
	return 0;
}