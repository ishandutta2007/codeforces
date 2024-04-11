#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;
const int max_n = 1e5 + 3;

int f(int mx, int c) {
	int l = 0, r = mx;
	while(r - l > 1) {
		int mid = (l + r) / 2;
		int num = 1;

		for(int i = 1;i <= c;i++) {
			if (mx / num < mid) break;
			num *= mid;
			if (i == c) l = mid;
		}
		if (l != mid) r = mid;
	}
	return l;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    vector<int> pr;
    for(int i = 2;i <= 65;i++) {
    	bool bad = false;
    	for(int j = 2;j * j <= i;j++)
    		if (i % j == 0) bad = true;
    	if (!bad) {
    		pr.emplace_back(i);
    	}
    }

   	map<int, int> a;
   	a[1];
   	for(int num = 2;num <= 1e6;num++) {
   		int v = num;
   		int id = 1;
   		for(int i = 2;i <= 65;i++) {
   			if (1000000000000000000LL / v < num) break;
   			//if (v >= 1e16 && num >= 1e2) cout << v * num << endl;
   			v = v * num;
   			if (pr[id] == i) {
   				a[v];
   				id++;
   			}
   		}
   	}

   	a[1000000000000000001LL];
   	int c = 1;
   	for(auto& i : a) {
   		i.se = c++;
   	}

   	int t;
   	cin >> t;
   	while(t--) {
   		int l, r;
   		cin >> l >> r;
   		int cnt = a.upper_bound(r)->se - a.lower_bound(l)->se;
   		int r1 = sqrtl(r), l1 = sqrtl(l);
   		if (l1 * l1 != l) l1++;
   		cnt += r1 - l1 + 1;
   		cnt -= a.upper_bound(r1)->se - a.lower_bound(l1)->se;
   		cout << cnt << endl;
   	}
}