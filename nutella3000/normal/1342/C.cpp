#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;


int cnt(int r, int k, int a, int b) {
	//cout << k << " ";
	int res = r / (a * b) * b;
	r %= a * b;
	if (r >= k * b) {
		r -= k * b - 1;
		res += min(r, b);
	}

	return res;
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
    	int a, b, q;
    	cin >> a >> b >> q;
    	if (a > b) swap(a, b);

    	vector<bool> good(a);
    	for(int i = 0;i < a;i++) {
    		if (i * b % a != 0)  good[i] = true;
    	}

    	while(q--) {
    		int l, r;
    		cin >> l >> r;
    		int res = 0;
    		for(int i = 0; i < a;i++) {
    			if (good[i]) res += cnt(r, i, a, b) - cnt(l - 1, i, a, b);
    		}

    		cout << res << " ";
    	}
    	cout << endl;
    }
}