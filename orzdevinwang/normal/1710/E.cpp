#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 2e5 + 7; 
int n, m, x, y;
int a[N], b[N];
int len[N];
int f[N], g[N]; 
int A[N], B[N];
ll Hall() {
	ll ns = 0, pre = 0;
	L(i, 1, n) A[i] = f[i];
	L(i, 1, m) B[i] = g[i]; 
	sort(A + 1, A + n + 1);
	sort(B + 1, B + m + 1);
	int j = 0;
	L(i, 1, n) {
		pre += A[i];
		while(j < m && B[j + 1] < i) ++j, pre += B[j];
		ns = max(ns, (ll) i * j - pre);
	}
	return ns;
}
bool check(int w) {
	R(i, n, 1) {
		len[i] = len[i + 1];
		while(len[i] < m && a[i] + b[len[i] + 1] <= w) ++len[i];
	}
	if(len[x] >= y) return true; 
	me(f, 0), me(g, 0);
	L(i, 1, n) f[i] = len[i], g[len[i]] += 1;
	R(i, m, 1) g[i] += g[i + 1];
	L(i, 1, n) f[i] = m - f[i];
	L(i, 1, m) g[i] = n - g[i];
	ll ha = Hall();
	f[x] -= 1;
	if(ha != Hall()) return true;
	f[x] += 1, g[y] -= 1;
	return ha != Hall();
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i];
	L(i, 1, m) cin >> b[i];
	x = a[1], y = b[1];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	x = lower_bound(a + 1, a + n + 1, x) - a;
	y = lower_bound(b + 1, b + m + 1, y) - b;
	int l = 0, r = 1e9 + 7, ns = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			ns = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ns << '\n';
	return 0;
} 
/*
 Hall 
|U| - \max_{S \in U} (|S| - |E_S|)
 \max_{S \in U} (|S| - |E_S|)

 |S|  
 -  -  +  =  -  -  

 V  \max_{S \in U} (|S| - |E_{S}|)  win 
*/