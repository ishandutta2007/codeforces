#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 15007, B = 300, inf = 1e9;

int n;
struct fwt { //  add,  min 
	int f[N]; // i : [i, i + low(i)) 
	void init (int x = inf) { L(i, 1, n) f[i] = x; }
	inline void add (int x, int k) {
		for (; x; x -= x & -x) 
			f[x] = min(f[x], k);
	}
	inline int query (int x) {
		int res = inf;
		for (; x <= n; x += x & -x) 
			res = min(res, f[x]);
		return res;
	}
	inline int findp (int x) {
		int s = 0;
		R(i, 18, 0) if (s + (1 << i) <= n && f[s + (1 << i)] <= x) s += 1 << i;
		return s;
	}
} f[B + 5], g[B + 5]; 
/* f : ; g :  */
int vl[N][B + 5], cl[N][B + 5];
int a[N], ct;
int calc1 () {
	L(i, 1, n) L(j, 0, B) vl[i][j] = inf, cl[i][j] = 0;
	L(i, 0, B + 1) f[i].init (inf), g[i].init (inf);
	f[1].add(a[1], a[1]), g[1].add(a[1], a[1]);
	f[0].add(a[1], a[1]), g[0].add(a[1], a[1]);
	L(i, 2, n) {
		R(j, B - 1, 0) {
			ct = f[j].findp (a[i]);
			if(ct) f[j + 1].add (ct, a[i]);	
			g[j + 1].add (a[i], g[j].query (a[i]));
		}
		L(j, 0, B) if(vl[i][j] < inf) g[j].add (a[i], vl[i][j]);
		L(j, 0, B) if(cl[i][j]) f[j].add (cl[i][j], a[i]);	
		L(j, 0, min(B - 1, n - i)) {
			cl[i + j][j + 1] = max(cl[i + j][j + 1], g[j].findp (a[i + j]));
			vl[i + j][j + 1] = min(vl[i + j][j + 1], f[j].query (a[i + j]));
		}
	}
	R(i, B, 0) if (f[i].query (1) < inf || g[i].query (1) < inf) return i;
	return -1;
}
int calc2 () {
	L(i, 1, n) L(j, 0, B) vl[i][j] = inf, cl[i][j] = 0;
	L(i, 0, B + 1) f[i].init (inf), g[i].init (inf);
	L(i, 1, n) f[0].add (i, i), g[0].add(i, i);
	L(i, 2, n) {
		R(j, B - 1, 0) {
			ct = f[j].findp (a[i]);
			if(ct) f[j + 1].add (ct, a[i]);	
			g[j + 1].add (a[i], g[j].query (a[i]));
		}
		L(j, 0, B) if(vl[i][j] < inf) g[j].add (a[i], vl[i][j]);
		L(j, 0, B) if(cl[i][j]) f[j].add (cl[i][j], a[i]);	
		L(j, 0, min(B - 1, n - i - 1)) {
			cl[i + j + 1][j + 1] = max(cl[i + j + 1][j + 1], g[j].findp (a[i + j + 1]));
			vl[i + j + 1][j + 1] = min(vl[i + j + 1][j + 1], f[j].query (a[i + j + 1]));
		}
	}
	R(i, B, 0) if (f[i].query (1) < inf || g[i].query (1) < inf) return i;
	return -1;
}
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	reverse(a + 1, a + n + 1);
	cout << max (calc1(), calc2()) << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) 
		Main ();
	return 0; 
}
/* https://www.cnblogs.com/zkyJuruo/articles/tricks.html */