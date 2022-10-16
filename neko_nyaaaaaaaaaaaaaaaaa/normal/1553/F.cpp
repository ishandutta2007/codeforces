#pragma comment(linker, "/stack:336777216")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

inline char gc() { // like getchar()
	static char buf[1 << 16];
	static size_t bc, be;
	if (bc >= be) {
		buf[0] = 0, bc = 0;
		be = fread(buf, 1, sizeof(buf), stdin);
	}
	return buf[bc++]; // returns 0 on EOF
}

int readInt() {
	int a, c;
	while ((a = gc()) < 40);
	if (a == '-') return -readInt();
	while ((c = gc()) >= 48) a = a * 10 + c - 480;
	return a - 48;
}
 
const int MAXN = 300005;

long long f[MAXN*4], pw[MAXN][2];

struct node2{
	int sum;
	long long st;
	int len;

	node2() {
		sum = st = len = 0;
	}
};

node2 merge(node2 l, node2 r) {
	node2 ans;
	ans.sum = l.sum + r.sum;
	ans.st = l.st + r.st + 1LL*r.sum*l.len;
	ans.len = l.len + r.len;

	return ans;
}

vector<node2> tr(1200005);
 
struct node{
	long long i1, i0;
 
	node operator + (const node &n2) {
		node n1;
 
		n1.i0 = (n2.i0 + i0);
		n1.i1 = (n2.i1 + i1);
 
		return n1;
	}
};
 
node lazy[MAXN * 4];
 
void init() {
	for (int i = 1; i < MAXN; i++) {
		pw[i][1] = (pw[i-1][1] + i);
	}
}
 
long long calc(node y, long long len) {
	long long res = y.i0 * len;
	res += pw[len][1] * y.i1;
 
	return res;
}
 
node change(node y, long long len) {
	if (len == 0) return y;
	node res;

	res.i0 = res.i1 = 0;

	res.i1 = (res.i1 + y.i1);
	res.i0 = (res.i0 + y.i1 * len);
 
	res.i0 = (res.i0 + y.i0);
 
	return res;
}
 
void push(int x, int l, int r) {
	int mid = (l + r)/2;
 
	f[x << 1] = (f[x << 1] + calc(lazy[x], mid - l + 1));
	lazy[x << 1] = lazy[x << 1] + lazy[x];
	lazy[x] = change(lazy[x], mid - l + 1);
 
	f[x << 1 | 1] = (f[x << 1 | 1] + calc(lazy[x], r - mid));
	lazy[x << 1 | 1] = lazy[x << 1 | 1] + lazy[x];
 
	lazy[x].i0 = lazy[x].i1 = 0;
}
 
void update(int x, int l, int r, int left, int right, node y) {
	if (l > right || r < left || l > r) return;
 
	if (left <= l && right >= r) {
		y = change(y, l - left);
		f[x] = (f[x] + calc(y, r - l + 1));
		lazy[x] = lazy[x] + y;
		return;
	} 
 
	int mid = (l + r)/2;
	push(x, l, r);
 
	update(x << 1, l, mid, left, right, y);
	update(x << 1 | 1, mid+1, r, left, right, y);
 
	f[x] = (f[x << 1] + f[x << 1 | 1]);
}
 
long long query(int x, int l, int r, int left, int right) {
	if (l > right || r < left || l > r) return 0;
	if (left <= l && right >= r) return f[x];
 
	int mid = (l + r)/2;
	push(x, l, r);
 
	return (query(x << 1, l, mid, left, right) + query(x << 1 | 1, mid + 1, r, left, right));
}

////////////////////////////////////

void update2(int nd, int start, int end, int index, int val) {
	if (start == end) {
		tr[nd].sum = val;
		tr[nd].st = val;
		tr[nd].len = 1;
	} else {
		int mid = (start + end)/2;
		
		if (start <= index && index <= mid) {update2(2*nd, start, mid, index, val);}
		else {update2(2*nd+1, mid+1, end, index, val);}
		
		tr[nd] = merge(tr[2*nd], tr[2*nd+1]);
	}
}

node2 query2(int nd, int start, int end, int l, int r) {
	if (r < start || end < l) {
		return node2();
	}
	if (l <= start && end <= r) {
		return tr[nd];
	}
	int mid = (start+end)/2;
	return merge(query2(2*nd, start, mid, l, r), query2(2*nd+1, mid+1, end, l, r));
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	for (int i = 1; i <= 300000; i++) {
		update2(1, 1, 300000, i, 0);
	}

	int n = readInt();
	long long ans = 0;
	while (n--) {
		int x = readInt();
		
		for (int i = 1; i <= 300000; i += x) {
			int l = i, r = min(300000, i+x-2);
			if (l <= r) {
				node2 nd = query2(1, 1, 300000, l, r);
				ans += nd.st;
			}
		}
		update2(1, 1, 300000, x, 1);

		ans += query(1, 1, 300000, x, x);
		cout << ans << ' ';

		for (int i = 0; i <= 300000; i += x) {
			int l = i+1, r = min(300000, i+x-1);
			if (l <= r) update(1, 1, 300000, l, r, {1, 0});
		}
	}

	return 0;
}