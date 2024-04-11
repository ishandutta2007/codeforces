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
const int N = 3e5 + 7;
const int mod = 998244353;
const int G = 3;
const int iG = (mod + 1) / G;
const int M = (1 << 20) + 10;
const db pi = acos(-1);
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int pp[M];
void NTT(int *f, int len, int flag) {
	for(int i = 0; i < len; i++) if(pp[i] < i) swap(f[pp[i]], f[i]);	
	for(int i = 2; i <= len; i <<= 1) 
		for(int j = 0, l = (i >> 1), ch = qpow(flag == 1 ? G : iG, (mod - 1) / i); j < len; j += i) 
			for(int k = j, now = 1; k < j + l; k ++) {
				int pa = f[k], pb = 1ll * f[k + l] * now % mod;
				f[k] = (pa + pb) % mod, f[k + l] = (pa - pb + mod) % mod, now = 1ll * now * ch % mod;
			}
	if(flag == -1) {
		int nylen = ny(len);
		L(i, 0, len - 1) f[i] = 1ll * f[i] * nylen % mod;
	}
}
priority_queue< pii > q;
struct Poly {
	vector<int> a; 
} f[N];
int a[M], b[M], B[N];
int cnt[N], p[N], ans[N << 1];
int n, k, tot;
void work(int l, int t) { 
	L(i, l, t - 1) if(cnt[i]) {
		f[++tot].a.clear();
		if(cnt[i] == 1) f[tot].a.push_back(1), f[tot].a.push_back(2), q.push(make_pair(-1, tot));
		else f[tot].a.push_back(1), f[tot].a.push_back(2), f[tot].a.push_back(1), q.push(make_pair(-2, tot));
	}
	if(tot == 0) {
		(ans[t + 1] += 1) %= mod;
		return;
	}
	while(q.size() != 1) {
		int sa = q.top().second;
		q.pop();
		int sb = q.top().second;
		q.pop();
		vector<int> tmpa, tmpb;
		int la = f[sa].a.size(), lb = f[sb].a.size();
		L(i, 0, f[sa].a.size() - 1) a[i] = f[sa].a[i];
		swap(tmpa, f[sa].a);
		L(i, 0, f[sb].a.size() - 1) b[i] = f[sb].a[i];
		swap(tmpb, f[sb].a);
		// cout << "----------------------------------------------------\n";
		// L(i, 0, la - 1) cout << a[i] << " ";
		// puts("");
		// L(i, 0, lb - 1) cout << b[i] << " ";
		// puts("");
		int lc = la + lb - 1;
		for(; lc != (lc & -lc); lc += (lc & -lc));
		for(int i = 0; i < lc; ++i) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lc >> 1)));
		NTT(a, lc, 1), NTT(b, lc, 1);
		for(int i = 0; i < lc; ++i) a[i] = 1ll * a[i] * b[i] % mod;
		NTT(a, lc, -1); 
		for(int i = 0; i < la + lb - 1; ++i) f[sa].a.push_back(a[i]);//, cout << a[i] << " ";
		// puts("");
		// cout << "-----------------------------------------------------\n";
		for(int i = 0; i < lc; ++i) a[i] = b[i] = 0;
		q.push(mkp(-f[sa].a.size(), sa));
	}
	int pp = q.top().second;
	L(i, 0, f[pp].a.size() - 1) (ans[i + t + 1] += f[pp].a[i]) %= mod; 
}
int main() {
	scanf("%d%d", &n, &k);
	L(i, 1, n) scanf("%d", &p[i]), cnt[p[i]] ++;
	L(i, 1, k) scanf("%d", &B[i]);
	sort(B + 1, B + k + 1);
	L(i, 1, k) work(B[i - 1], B[i]);
	int Q; scanf("%d", &Q);
	while(Q--) {
		int x; scanf("%d", &x);
		printf("%d\n", ans[x / 2]);
	}
	return 0;
} 
/*
5 1
1 2 3 4 5
3
4
4 8 10 14

*/