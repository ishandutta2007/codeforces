#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define i128 __int128
using namespace std;
const int N = 10007;
ll x[N];
int n, ord[N], mp[N], xa[N], cv[N], atot;
ll a[N], xv[N], ri[N], le[N];
int nxt[N], lst[N], ok[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n ; 
	L(i, 1, n) {
		cin >> a[i];
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return a[x] < a[y];
	});
	L(i, 1, n) xv[i] = a[ord[i]], xa[ord[i]] = i;
	L(i, 1, n) {
		int mn = xa[i]; 
		L(j, i, n) {
			mn = min(mn, xa[j]);
			ll V = xv[mn] * (j - i + 1);
			cv[mn] = max(cv[mn], j - i + 1);
			le[i] = max(le[i], V), ri[j] = max(ri[j], V);
		}
	}
	ll ns = 0, pre = 0;
	L(i, 1, n) pre = max(pre, ri[i]), ns = max(ns, pre + le[i + 1]);
	L(i, 1, n) 
		L(j, i, n) 
			ns = max(ns, (cv[i] - cv[j]) * xv[i] + cv[j] * xv[j]);
	
	R(i, n, 1) for(int u = i + 1; ; u = nxt[u]) 
		if(a[u] < a[i]) {
			nxt[i] = u;
			break;
		}
		
	L(i, 1, n) for(int u = i - 1; ; u = lst[u]) 
		if(a[u] < a[i]) {
			lst[i] = u;
			break;
		}
	
	L(i, 1, n) L(j, i + 1, n) if((a[i] <= a[j]) && nxt[i] > j) {
		int p = max(lst[j], i) + 1, fi = -1;
		for(fi = p; ; fi = nxt[fi]) if(a[fi] < a[i] + a[j]) break ;
		ns = max(ns, a[i] * (fi - 1 - lst[i]) + a[j] * (nxt[j] - p));
	}
	
	L(i, 1, n) L(j, i + 1, n) if((a[i] >= a[j]) && lst[j] < i) {
		int p = min(nxt[i], j) - 1, fi = -1;
		for(fi = p; ; fi = lst[fi]) if(a[fi] < a[i] + a[j]) break ;
		ns = max(ns, a[i] * (p - lst[i]) + a[j] * (nxt[j] - fi - 1));
	}
	
	L(j, 1, n) {
		L(i, 1, j - 1) ok[i] = n + 1;
		int posi = nxt[j];
		L(i, 1, xa[j] - 1) {
			while(posi <= n && a[posi] >= a[j] - xv[i]) ++posi;
			ok[ord[i]] = posi;
		} 
		L(i, 1, j - 1) if(a[j] >= a[i] && nxt[i] > j) {
			int nx = nxt[j], p = ok[i]; 
			ll dc = a[j] - a[i];
			ns = max(ns, a[i] * (nx - lst[i] - 1) + dc * (p - lst[j] - 1));
		}
	}
	
	L(i, 1, n) {
		L(j, i + 1, n) ok[j] = 0;
		int posi = lst[i];
		L(j, 1, xa[i] - 1) {
			while(posi && a[posi] >= a[i] - xv[j]) --posi;
			ok[ord[j]] = posi;
		} 
		L(j, i + 1, n) if(a[j] <= a[i] && lst[j] < i) {
			int nx = lst[i], p = ok[j];
			ll dc = a[i] - a[j];
			ns = max(ns, dc * (nxt[i] - p - 1) + a[j] * (nxt[j] - nx - 1));
		}
	}
	cout << ns << '\n';
	return 0;
} 
/*
4
2 3 3 1
ans : 9

5
5 7 7 7 3
ans : 28

5
4 3 10 11 8
ans : 33 
*/