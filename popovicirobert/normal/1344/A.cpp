#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int	i, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


  	cin >> t;
  	for(int tt = 1; tt <= t; tt++) {
  		int n;
  		cin >> n;
  		vector<int> a(n);
  		for(i = 0; i < n; i++) {
  			cin >> a[i];
  		}

  		map<int, int> fr;
  		for(i = 0; i < n; i++) {
  			int r = (i + a[i]) % n;
  			if(r < 0) {
  				r += n;
  			}
  			fr[r]++;
  		}

  		bool bad = false;
  		for(auto it : fr) {
  			if(it.second > 1) {
  				bad = true;
  			}
  		}

  		cout << (bad ? "NO" : "YES") << "\n";
  	}
    
    return 0;
}