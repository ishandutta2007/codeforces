#include <bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 1;
int n;
int a[max_n];
int pref[201][max_n];

int get(int col, int l, int r) {
	int res = pref[col][r];
	if (l != 0) res -= pref[col][l - 1];
	return res;
}

int th[max_n];


void build() {
	for(int i = 0;i < n;i++) {
		int l = -1;
		int r = n;
		while(r - l > 1) {
			int m = ((l + r) >> 1);
			if (get(a[i], m, n - 1) < get(a[i], 0, i)) r = m;
			else l = m;
		}

		th[i] = l;
	}
}


void solve() {
	int res = 0;
	for(int i = 0;i <= 200;i++) res = max(res, get(i, 0, n - 1));

	for(int i = 0;i < n;i++) {
		if (th[i] <= i) continue;
		int qq = 2 * get(a[i], 0, i);
		int ww = 0;
		for(int col = 0;col <= 200;col++) {
			ww = max(ww, get(col, i + 1, th[i] - 1));
		} 
		qq += ww;
		res = max(qq, res);
	}

	cout << res << '\n';
}





signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);


   	int t;
   	cin >> t;
   	while(t--) {
   		cin >> n;

   		for(int i = 0;i <= 200;i++) {
   			for(int j = 0;j < n;j++) pref[i][j] = 0;
   		}

   		for(int i = 0;i < n;i++) {
   			cin >> a[i];
   			pref[a[i]][i] = 1;
   			for(int j = 0;j <= 200;j++) {
   				if (i != 0)	pref[j][i] += pref[j][i - 1];
   			}
   		}

   		build();
   		solve();
   	}
}