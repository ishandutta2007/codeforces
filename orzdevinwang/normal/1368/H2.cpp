#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
const int inf = 1e9 + 7;
struct Martix {
	int G[2][2];
	void clear() { L(i, 0, 1) L(j, 0, 1) G[i][j] = inf; }
};
Martix make(int x, int y) { 
	Martix res; 
	res.G[0][0] = x, res.G[1][1] = y, res.G[0][1] = res.G[1][0] = inf; 
	return res; 
}
Martix operator * (Martix aa, Martix bb) {
	Martix res; res.clear();
	L(i, 0, 1) L(j, 0, 1) L(k, 0, 1) res.G[i][j] = min(res.G[i][j], aa.G[i][k] + bb.G[k][j]);
	return res;
}
struct SegmentTree1 { // 
	int n, m;
	Martix f[4][N]; bool flaga[N], flagb[N];
	Martix fmake(int x) { 
		int y = 2 - x; 
		Martix res; res.G[0][0] = x, res.G[0][1] = x + m, res.G[1][1] = y, res.G[1][0] = y + m;
		return res;
	}
	void upd(int id) {
		f[0][id] = f[0][id << 1] * f[0][id << 1 | 1];
		f[1][id] = f[1][id << 1] * f[1][id << 1 | 1];
		f[2][id] = f[2][id << 1] * f[2][id << 1 | 1];
		f[3][id] = f[3][id << 1] * f[3][id << 1 | 1];
	}
	void Build(int id, int L, int R, char *sa, char *sb) {
		if(L == R) {
			bool ga = (sa[L] == 'R'), gb = (sb[L] == 'R');
			f[0][id] = fmake((ga) + (gb));
			f[1][id] = fmake((ga) + (!gb));
			f[2][id] = fmake((!ga) + (gb));
			f[3][id] = fmake((!ga) + (!gb));
		}
		else {
			int mid = (L + R) / 2;
			Build(id << 1, L, mid, sa, sb), Build(id << 1 | 1, mid + 1, R, sa, sb);
			upd(id);
		}
	}
	void build(char *sa, char *sb) { Build(1, 1, n, sa, sb); }
	void filpa(int x) { 
		flaga[x] ^= 1; 
		swap(f[0][x], f[1][x]); 
		swap(f[2][x], f[3][x]); 
	}
	void filpb(int x) {
		flagb[x] ^= 1; 
		swap(f[0][x], f[2][x]); 
		swap(f[1][x], f[3][x]); 
	}
	void pushdown(int x) { 
		if(flaga[x]) filpa(x << 1), filpa(x << 1 | 1), flaga[x] = 0; 
		if(flagb[x]) filpb(x << 1), filpb(x << 1 | 1), flagb[x] = 0; 
	}
	void gga(int id, int L, int R, int l, int r) {
		if(l <= L && R <= r) return filpa(id);
		int mid = (L + R) / 2;
		pushdown(id);
		if(l <= mid) gga(id << 1, L, mid, l, r);
		if(r > mid) gga(id << 1 | 1, mid + 1, R, l, r);
		upd(id);
	}
	void ggb(int id, int L, int R, int l, int r) {
		if(l <= L && R <= r) return filpb(id);
		int mid = (L + R) / 2;
		pushdown(id);
		if(l <= mid) ggb(id << 1, L, mid, l, r);
		if(r > mid) ggb(id << 1 | 1, mid + 1, R, l, r);
		upd(id);
	}
	void changea(int l, int r) { gga(1, 1, n, l, r); }
	void changeb(int l, int r) { ggb(1, 1, n, l, r); }
} sega, segb;
struct SegmentTree2 { 
	int n;
	int fa[N], fb[N]; bool flag[N];
	void upd(int id) {
		fa[id] = fa[id << 1] + fa[id << 1 | 1], fb[id] = fb[id << 1] + fb[id << 1 | 1];
	}
	void Build(int id, int L, int R, char *s) {
		if(L == R) fa[id] = (s[L] == 'R'), fb[id] = (s[L] == 'B');
		else {
			int mid = (L + R) / 2;
			Build(id << 1, L, mid, s), Build(id << 1 | 1, mid + 1, R, s);
			upd(id);
		}
	}
	void build(char *s)  { Build(1, 1, n, s); }
	void filp(int x) { swap(fa[x], fb[x]), flag[x] ^= 1; }
	void pushdown(int x) { if(flag[x]) filp(x << 1), filp(x << 1 | 1), flag[x] = 0; }
	void gg(int id, int L, int R, int l, int r) {
		if(l <= L && R <= r) return filp(id);
		int mid = (L + R) / 2;
		pushdown(id);
		if(l <= mid) gg(id << 1, L, mid, l, r);
		if(r > mid) gg(id << 1 | 1, mid + 1, R, l, r);
		upd(id);
	}
	void change(int l, int r) { gg(1, 1, n, l, r); }
} segup, segdown, seglef, segrig;
// int dp[2]; // 0 : Blue; 1 : Red
// int get(char *lef, char *rig, char *up, char *down, int n, int m) {
// 	dp[0] = dp[1] = 0;
// 	L(i, 1, m) dp[0] += (up[i] == 'R'), dp[1] += (up[i] == 'B');
// 	L(i, 1, n) {
// 		dp[0] += (lef[i] == 'R') + (rig[i] == 'R');
// 		dp[1] += (lef[i] == 'B') + (rig[i] == 'B');
// 		dp[0] = min(dp[0], dp[1] + m), dp[1] = min(dp[1], dp[0] + m);
// 	}
// 	L(i, 1, m) dp[0] += (down[i] == 'R'), dp[1] += (down[i] == 'B');
// 	return min(dp[0], dp[1]);
// }
char lef[N], rig[N], up[N], down[N];
int now, len;
int n, m, q;
int getmin(Martix aa) {
	return min(min(aa.G[0][0], aa.G[0][1]), min(aa.G[1][0], aa.G[1][1]));
}
int getminn(Martix aa, int bb){
	return min(aa.G[0][bb], aa.G[1][bb]);
}
void print() {
	// cout << "Martix : \n";
	// L(i, 0, 1) {
	// 	L(j, 0, 1) printf("%d ", sega.f[0][1].G[i][j]);
	// 	puts("");
	// }
	Martix aa = make(segup.fa[1], segup.fb[1]) * sega.f[0][1] * make(segdown.fa[1], segdown.fb[1]);
	Martix bb = make(seglef.fa[1], seglef.fb[1]) * segb.f[0][1] * make(segrig.fa[1], segrig.fb[1]);
	// cout << getminn(aa, 0) << " " << getminn(aa, 1) << endl;
	// cout << getminn(bb, 0) << " " << getminn(bb, 1) << endl;
	printf("%d\n", min(getmin(aa), getmin(bb)));
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	scanf("%s%s%s%s", lef + 1, rig + 1, up + 1, down + 1);
	seglef.n = segrig.n = n, segup.n = segdown.n = m;
	sega.n = segb.m = n, segb.n = sega.m = m;
	sega.build(lef, rig), segb.build(up, down);
	// cout << "QwQ\n";
	seglef.build(lef), segrig.build(rig), segup.build(up), segdown.build(down);
	// cout << "Hoho! baoling!\n";
	print();
	while(q--) {
		char opt[7]; int l, r; scanf("%s%d%d", opt, &l, &r);
		if(opt[0] == 'U') segup.change(l, r), segb.changeb(l, r);
		if(opt[0] == 'D') segdown.change(l, r), segb.changea(l, r);
		if(opt[0] == 'L') seglef.change(l, r), sega.changeb(l, r);
		if(opt[0] == 'R') segrig.change(l, r), sega.changea(l, r);
		print();
	}
	return 0;
}
/*
1. 9 7
2. 9 9
*/
/*
----
4 4
4 4
----
5 5
5 5
----
6 6
6 6
----
7 7
7 7
----
9 9

4 5
0 5
1 6
1 6
----
1 8
1 6
----
2 7
2 7
----
4 7
4 7
----
9 7

*/