#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, tot, a[N], f[N]; 
int L, R;
int edge_id, u[N], v[N], val[N];
void add(int U, int V, int VAL) {
	++edge_id, u[edge_id] = U, v[edge_id] = V, val[edge_id] = VAL;
}
void Main() {
	cin >> L >> R, R = R - L + 1, tot = 1;
	int st;
	if(L == 1) st = 1;
	else ++tot, st = tot, add(1, tot, L - 1);
	f[0] = st, f[1] = ++tot, add(st, tot, 1);
	L(i, 2, 20) {
		f[i] = ++tot, add(st, f[i], 1);
		L(j, 1, i - 1) add(f[j], f[i], 1 << (j - 1));
	}
	++tot;
	add(st, tot, 1), --R;
	int now = 1;
	L(i, 1, 20) if(R >> (i - 1) & 1) add(f[i], tot, now), now += (1 << (i - 1));
	cout << "YES\n";
	cout << tot << " " << edge_id << "\n";
	L(i, 1, edge_id) cout << u[i] << " " << v[i] << " " << val[i] << "\n";
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}