#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = (1 << 22) + 1;
int n, m, a[N];
int f[N], mc[N];
bool vis[N], ok[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		cin >> a[i];
		vis[a[i]] = true;
		ok[((1 << n) - 1) ^ a[i]] = true;
	}
	L(i, 0, (1 << n) - 1) 
		if(vis[i]) f[i] = mc[i] = i;
		else f[i] = mc[i] = -1;
	L(i, 0, n - 1) 
		L(j, 0, (1 << n) - 1) if(!(i >> j & 1)) 
			ok[j] |= ok[j | (1 << i)];
	L(i, 0, (1 << n) - 1) if(ok[i]) {
		L(j, 0, n - 1) if(i >> j & 1) {
			int to = i ^ (1 << j);
			if(mc[to] != -1) {
				if(mc[i] == -1) mc[i] = mc[to];
				else f[find(mc[to])] = find(mc[i]);
			} 
		}
	}
	L(i, 1, m) {
		vis[a[i]] = true;
		int c = ((1 << n) - 1) ^ a[i];
		if(mc[c] != -1) f[find(a[i])] = find(mc[c]);
	}
	int cnt = 0;
	L(i, 0, (1 << n) - 1) cnt += f[i] == i;
	cout << cnt << '\n';
	return 0;
}