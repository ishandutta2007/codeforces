#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, O = 5e5, inf = 1e9;
int n, m, a[N], arr[N];
int mnl[N], mxr[N], haha[N];
map < int, vi > mp;
void Main () {
	cin >> n >> m;
	L(i, 1, n) mnl[i] = n + 1;
	L(i, 1, n) mxr[i] = 0;
	L(i, 1, n) cin >> a[i];
	mp.clear();
	L(i, 1, n) mp[a[i]].emplace_back(i);
	
	L(i, 1, m) {
		int l, r;
		cin >> l >> r;
		mxr[l] = max(mxr[l], r);
		mnl[r] = min(mnl[r], l);
	}
	L(i, 2, n) mxr[i] = max(mxr[i], mxr[i - 1]);
	R(i, n - 1, 1) mnl[i] = min(mnl[i], mnl[i + 1]);
	int fi = 1;
	L(i, 1, n) haha[i] = 1e9;
	for(auto x : mp) {
		vi c = x.second;
		L(i, 0, sz(c) - 2) 
			if(mxr[c[i]] >= c[i + 1]) {
				int to = upper_bound(c.begin(), c.end(), mxr[c[i]]) - c.begin() - 1;
				fi = max(fi, c[to - 1]);
				haha[n] = min(haha[n], c[i + 1]);
				haha[c[to] - 1] = min(haha[c[to] - 1], c[i]);
			}
	}
	R(i, n - 1, 1) 
		haha[i] = min(haha[i], haha[i + 1]); 
	int ns = 1e9;
	L(i, fi, n) 
		ns = min(ns, i - haha[i] + 1);
//	L(i, 1, n) 
//		cout << haha[i] << ",";
//	cout << '\n';
	cout << max(ns, 0) << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}

/*
1
1 4
1
*/