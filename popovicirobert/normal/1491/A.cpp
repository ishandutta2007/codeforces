#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
   	
   	int n, q;
  	cin >> n >> q;
  	vector<int> a(n + 1);
  	vector<int> freq(2);
  	for (int i = 1; i <= n; i++) {
  		cin >> a[i];
  		freq[a[i]]++;
  	}

  	while (q--) {
  		int t, x;
  		cin >> t >> x;
  		if (t == 1) {
  			freq[a[x]]--;
  			a[x] = 1 - a[x];
  			freq[a[x]]++;
  		} else {
  			if (freq[1] < x) {
  				cout << 0 << "\n";
  			}
  			else {
  				cout << 1 << "\n";
  			}
  		}
  	}

    return 0;
}