#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 19), M = N * 2 + 7;
int pool[N * 22 * 4], * cur = pool;
int n, k, * mx[M], * mn[M], a[N];
int ns[N], f[20][N];
void build (int x, int dep) {
	mx[x] = cur, cur += 1 << dep;
	mn[x] = cur, cur += 1 << dep;
//	cout << x << " : " << dep << "\n"; 
	L(i, 0, (1 << dep) - 1) mn[x][i] = 1e9, mx[x][i] = -1e9;
	if(dep == 0) return ;
	build(x * 2, dep - 1), build (x * 2 + 1, dep - 1);
}
void ins (int x) {
	int now = 1, w = x;
	R(i, k - 1, 0) {
		int c = w >> i & 1;
		now <<= 1, now |= c;
	}
//	cout << x << " : " << now << "\n";
	mx[now][0] = max(mx[now][0], w), mn[now][0] = min(mn[now][0], w);
}
void calc (int x, int dep, int l, int r) {
	if(dep == 0) return ;
	int mid = (l + r) >> 1;
	calc (x * 2, dep - 1, l, mid), calc (x * 2 + 1, dep - 1, mid + 1, r);
	L(i, 0, (1 << (dep - 1)) - 1) 
		f [dep][i] = min(f[dep][i], mn[x * 2 + 1][i] - mx[x * 2][i]);
	L(i, 0, (1 << (dep - 1)) - 1) 
		f [dep][i ^ (1 << (dep - 1))] = min(f[dep][i ^ (1 << (dep - 1))], mn[x * 2][i] - mx[x * 2 + 1][i] + (1 << dep));
	
	L(i, 0, (1 << dep) - 1) {
		int c = i & (1 << (dep - 1)), g = i ^ c;
		mx[x][i] = max(mx[x * 2][g] ^ c, mx[x * 2 + 1][g] ^ c);
		mn[x][i] = min(mn[x * 2][g] ^ c, mn[x * 2 + 1][g] ^ c);
	}
//	cout << x << " : " << l <<  " to " << r << " : \n";
//	L(i, 0, (1 << dep) - 1) cout << mx[x][i] << " ";
//	cout << "\n";
//	L(i, 0, (1 << dep) - 1) cout << mn[x][i] << " ";
//	cout << "\n";
} 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(f, 0x3f, sizeof(f));
	cin >> n >> k;
	build(1, k);
	L(i, 1, n) cin >> a[i], ins (a[i]);
	calc (1, k, 0, (1 << k) - 1);
	L(i, 0, (1 << k) - 1) {
		int ns = 1e9;
		L(j, 0, k) ns = min(ns, f[j][i & ((1 << j) - 1)]);
		cout << ns << " ";
	}
	return 0;
}