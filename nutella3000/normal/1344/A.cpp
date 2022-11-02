#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pii pair<int, int>
//#define sz(a) ((int)a.size())  
typedef long double ld;

const int inf = 1e9 + 7;




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
   		int n;
   		cin >> n;
   		bool bad = false;
   		set<int> b;
   		for(int i = 0;i < n;i++) {
   			int v;
   			cin >> v;
   			v += i;

   			v = (v % n + n) % n;
   			if (b.find(v) != b.end()) bad = true;
   			b.emplace(v);
   		}

   		if (bad) cout << "NO" << endl;
   		else cout << "YES" << endl;
   	}
}