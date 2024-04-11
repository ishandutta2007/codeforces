#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;

const int N = 1 << 20, mod = 1e9 + 7;


struct segt {
	
	int a[N], sum[N], tag[N];
	void build(int x, int L, int R) {
		tag[x] = 1;
		if(L == R) return sum[x] = a[L], void ();
		int mid = (L + R) >> 1;
		build(x << 1, L, mid), build(x << 1 | 1, mid + 1, R);
		sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % mod;
	}
	
	void add (int x, int L, int R, int l, int r, int w) {
		if(l <= L && R <= r) 
			return tag[x] = (ll) tag[x] * w % mod, sum[x] = (ll) sum[x] * w % mod, void ();
		int mid = (L + R) >> 1;
		if(l <= mid) add (x << 1, L, mid, l, r, w);
		if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, w);
		sum[x] = (ll) tag[x] * (sum[x << 1] + sum[x << 1 | 1]) % mod;
	}
	
	int query(int x, int L, int R, int l, int r) {
		if(l <= L && R <= r) return sum[x];
		int mid = (L + R) >> 1, sum = 0;
		if(l <= mid) (sum += query(x << 1, L, mid, l, r)) %= mod;
		if(r > mid) (sum += query(x << 1 | 1, mid + 1, R, l, r)) %= mod;
		return (ll) sum * tag[x] % mod;
	}
	
} seg[4];

int inv[N];
int n, a[N], ns;
int arr[N], mp[N], atot;
int lst[N], nxt[N];

int stk1[N], tp1;
int stk2[N], tp2;

void mut1(int l, int r, int x) {
	seg[0].add(1, 1, n, l, r, x);
	seg[1].add(1, 1, n, l, r, x);
}

void mut2(int l, int r, int x) {
	seg[0].add(1, 1, n, l, r, x);
	seg[2].add(1, 1, n, l, r, x);
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n) cin >> a[i], arr[++atot] = a[i];
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) a[i] = lower_bound(arr + 1, arr + atot + 1, a[i]) - arr;
	
	inv[1] = 1;
	L(i, 2, n) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	
	L(i, 1, n) {
		if(mp[a[i]]) 
			lst[i] = mp[a[i]], nxt[mp[a[i]]] = i;
		mp[a[i]] = i;
	}
	L(i, 1, n) if(!nxt[i]) nxt[i] = n + 1;
	L(i, 1, n) nxt[i] -= 1, lst[i] += 1;
	
	L(i, 1, n) seg[0].a[i] = mod - 1, seg[1].a[i] = 1, seg[2].a[i] = i, seg[3].a[i] = mod - i;
	L(i, 0, 3) seg[i].build(1, 1, n);
	
	int pos = 1;
	L(i, 1, n) {
		while(tp1 && lst[stk1[tp1]] < lst[i]) 
			mut1(stk1[tp1 - 1] + 1, stk1[tp1], inv[lst[stk1[tp1]]]), -- tp1;	
		stk1[++tp1] = i, mut1(stk1[tp1 - 1] + 1, stk1[tp1], lst[stk1[tp1]]);
		
		while(tp2 && nxt[stk2[tp2]] > nxt[i]) 
			mut2(stk2[tp2 - 1] + 1, stk2[tp2], inv[nxt[stk2[tp2]]]), -- tp2;
		stk2[++tp2] = i, mut2(stk2[tp2 - 1] + 1, stk2[tp2], nxt[stk2[tp2]]);
		
		pos = max(pos, lst[i]);
		
		L(j, 0, 3) 
			(ns += (ll) ((j & 1) ? i : 1) * seg[j].query(1, 1, n, pos, i) % mod) %= mod;
	}
	
	cout << ns << '\n';
	return 0;
}