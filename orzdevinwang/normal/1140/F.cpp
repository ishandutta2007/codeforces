// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 3e5 + 7;
const int MAXN = 3e5;
int m, tot;
map<int, int> mp[N];
struct node {
	int x, y, l, r;
} ask[N];
struct UFS {
	int f[N << 1], siza[N << 1], sizb[N << 1];
	stack< pair<pii, int> > stk;
	int find(int x) {
		return f[x] == x ? x : find(f[x]);
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		if(siza[x] + sizb[x] > siza[y] + sizb[y]) swap(x, y);
		stk.push(mkp(mkp(siza[x], sizb[x]), x));
		siza[y] += siza[x], sizb[y] += sizb[x], f[x] = y;
	}
	void revoke() {
		int u = stk.top().second;
		siza[f[u]] -= stk.top().first.first;
		sizb[f[u]] -= stk.top().first.second;
		f[u] = u, stk.pop();
	}
} ufs;
vector<int> ve[N << 2];
void add(int id, int L, int R, int x) {
	if(ask[x].l <= L && R <= ask[x].r) return ve[id].push_back(x), void();
	int mid = (L + R) / 2;
	if(ask[x].l <= mid) add(id << 1, L, mid, x);
	if(ask[x].r > mid) add(id << 1 | 1, mid + 1, R, x);
}
ll res = 0;
void divide(int id, int L, int R) {
	ll las = res; int cnt = 0;
	for(int x : ve[id]) {
		int fx = ufs.find(ask[x].x), fy = ufs.find(ask[x].y + MAXN);
		if(fx ^ fy) {
			cnt ++;
			res += 1ll * ufs.siza[fx] * ufs.sizb[fy]; 
			res += 1ll * ufs.sizb[fx] * ufs.siza[fy]; 
			ufs.merge(fx, fy); 
		}
	}
	if(L == R) printf("%lld ", res);
	else {
		int mid = (L + R) / 2;
		divide(id << 1, L, mid), divide(id << 1 | 1, mid + 1, R);
	}
	while(cnt --) ufs.revoke();
	res = las;
}
int main() {
	scanf("%d", &m);
	L(i, 1, m) {
		int X, Y; scanf("%d%d", &X, &Y);
		if(mp[X].count(Y)) ask[mp[X][Y]].r = i - 1, mp[X].erase(Y);
		else mp[X][Y] = ++tot, ask[tot].x = X, ask[tot].y = Y, ask[tot].l = i;
	}
	L(i, 1, tot) if(!ask[i].r) ask[i].r = m;
	L(i, 1, tot) add(1, 1, m, i);
//	cout << "GeorgeAK I Baoling!\n"; 
	L(i, 1, 3e5) ufs.f[i] = i, ufs.f[i + MAXN] = i + MAXN, ufs.siza[i] = 1, ufs.sizb[i + MAXN] = 1;
	divide(1, 1, m);
	puts("");
	return 0;
}