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
const int M = N * 20;
const int mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x * f; 
}
int seg[M], ch[M][2], tot;
void add(int &id, int fid, int L, int R, int wz) {
	if(!id) id = ++tot;
	seg[id] = seg[fid] + 1;
	if(L == R) return;
	int mid = (L + R) >> 1;
	if(wz <= mid) ch[id][1] = ch[fid][1], add(ch[id][0], ch[fid][0], L, mid, wz);
	else ch[id][0] = ch[fid][0], add(ch[id][1], ch[fid][1], mid + 1, R, wz);
}
int qry(int ida, int idb, int L, int R, int val) {
	if(seg[idb] - seg[ida] <= val) return 0;
	if(L == R) return L;
	int mid = (L + R) >> 1, res;
	res = qry(ch[ida][0], ch[idb][0], L, mid, val); if(res) return res;
	res = qry(ch[ida][1], ch[idb][1], mid + 1, R, val); if(res) return res;
	return 0;
}
int n, m, a[N], hd[N];
int main() {
	n = read(), m = read();
	L(i, 1, n) a[i] = read(), add(hd[i], hd[i - 1], 1, n, a[i]);
	while(m--) {
		int l = read(), r = read(), k = read(), ans = qry(hd[l - 1], hd[r], 1, n, (r - l + 1) / k);
		printf("%d\n", ans ? ans : -1);
	}
	return 0;
}