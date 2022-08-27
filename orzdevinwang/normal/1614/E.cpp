#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1 << 19, M = N << 5, Mod = 1e9 + 1;
int n, lst, rt;
int ch[M][2], mn[M], tag[M], tot;
inline void build (int &x, int L, int R) { 
	x = ++tot, mn[x] = L, tag[x] = 0;
}
inline void ad (int x, int w) {
	mn[x] += w, tag[x] += w;
}
void Push (int x, int L, int R) {
	int mid = (L + R) >> 1;
	if(!ch[x][0]) build (ch[x][0], L, mid);
	if(!ch[x][1]) build (ch[x][1], mid + 1, R);
	ad (ch[x][0], tag[x]), ad (ch[x][1], tag[x]), tag[x] = 0;
}
void add (int &x, int L, int R, int l, int r, int w) { 
	if (!x) build (x, L, R);
	if (l <= L && R <= r) return ad (x, w), void ();
	int mid = (L + R) >> 1;
	Push (x, L, R);
	if (l <= mid) add (ch[x][0], L, mid, l, r, w);
	if (r > mid) add (ch[x][1], mid + 1, R, l, r, w);
	mn[x] = min (mn[ch[x][0]], mn[ch[x][1]]);
}
int query (int &x, int L, int R, int w) { //  <= w  
	if (!x) build (x, L, R);
	if (mn[x] > w) return -1;
	if (L == R) return L;
	int mid = (L + R) >> 1;
	Push (x, L, R);
	if (mn[ch[x][1]] <= w) return query (ch[x][1], mid + 1, R, w);
	else return query (ch[x][0], L, mid, w);
}
int get (int &x, int L, int R, int p) {
	if (!x) build (x, L, R);
	if(L == R) return mn[x];
	int mid = (L + R) >> 1;
	Push (x, L, R);
	if (p <= mid) return get (ch[x][0], L, mid, p);
	else return get (ch[x][1], mid + 1, R, p);
}
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		int t;
		cin >> t;
		
//		cout << "MN = " << mn[rt] << '\n';
		
		int p = query (rt, 0, Mod, t - 1);
		int cp = query (rt, 0, Mod, t);
//		cout << p << ' ' << cp << '\n';
		if (p >= 0) add (rt, 0, Mod, 0, p, 1);
		add (rt, 0, Mod, cp + 1, Mod, -1); 
		
		int k;
		cin >> k;
		while (k--) {
			int w;
			cin >> w;
			(w += lst) %= Mod;
			cout << (lst = get(rt, 0, Mod, w)) << '\n';
		}
	}
	return 0;
}