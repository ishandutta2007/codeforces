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
   	
   	int q;
   	cin >> q;
  	while (q--) {
  		int n;
  		cin >> n;
  		vector<int> arr(n);
  		for (int i = 0; i < n; i++) {
  			cin >> arr[i];
  		}

  		vector<ll> counter(n);
  		ll answer = 0;
  		for (int i = 0; i < n; i++) {
  			for (int j = i - 2; j >= 0; j--) {
  				if (arr[j] + j >= i && j + 2 <= i) {
  					counter[i]++;
  				}
  			}	
  			if (i > 0) {
  				counter[i] += max(0LL, counter[i - 1] - (arr[i - 1] - 1));
  			}
  			answer += max(0LL, arr[i] - counter[i] - 1);
  		}

  		cout << answer << "\n";
  	}

    return 0;
}