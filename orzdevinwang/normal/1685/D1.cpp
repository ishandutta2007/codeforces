#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
int n, p[N], f[N], q[N], vis[N];
int mp[N], to[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
} 
void Main() {
	cin >> n ;
	L(i, 1, n) cin >> q[i], mp[q[i]] = i;
	L(i, 1, n) vis[i] = 0;
	L(i, 1, n) if(!vis[i]) {
		int u = i;
		while(!vis[u]) {
			vis[u] = i;
			f[u] = i; 
			u = q[u];
		} 
	}
	L(i, 1, n) to[i] = mp[i];
	L(i, 1, n - 1) if(find(i) != find(i + 1)) {
		swap(to[i], to[i + 1]);
		f[find(i)] = find(i + 1);
	}
	
//	L(i, 1, n) cout << to[i] << ' ';
//	cout << '\n';
	int u = 1;
	cout << 1 << ' ';
	while(to[u] != 1) u = to[u], cout << u << ' ';
	cout << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	cin >> n;
//	L(i, 1, n) p[i] = q[i] = i;
//	int xmx = 0;
//	do {
//		L(i, 1, n) q[i] = i;
//		int ret = 1e9;
//		do {
//			int sum = 0;
//			L(j, 1, n) 
//				sum += abs(q[j] - p[q[j % n + 1]]); 
//			ret = min(ret, sum);
//		} while(next_permutation(q + 1, q + n + 1));
////		cout << ret << '\n';
////		if(ret) {
//			L(i, 1, n) vis[i] = 0;
//			int cyc = -2;
//			L(i, 1, n) if(!vis[i]) {
//				int u = i;
//				while(!vis[u]) {
//					vis[u] = true; 
//					u = p[u];
//				} 
//				cyc += 2;
//			}
//			if(cyc == 0) {
//			}
//			assert(cyc == ret);
////		}
//		xmx = max(xmx, ret);
//	} while(next_permutation(p + 1, p + n + 1));
//	cout << xmx << endl;
	int t ;
	cin >> t;
	while(t--) Main();
	return 0;
}