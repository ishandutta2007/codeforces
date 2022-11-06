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
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
   	
  	cin >> n >> m;

  	string s, t;
  	cin >> s >> t;
   	
  	vector<int> prefPos(m);
  	int pos = 0;
  	for (int i = 0; i < m; i++) {
  		while (s[pos] != t[i]) {
  			pos++;
  		}
  		prefPos[i] = pos++;
  	}

  	vector<int> suffPos(m);
  	pos = n - 1;
  	for (int i = m - 1; i >= 0; i--) {
  		while (s[pos] != t[i]) {
  			pos--;
  		}
  		suffPos[i] = pos--;
  	}

  	int ans = 0;
  	for (int i = 0; i + 1 < m; i++) {
  		ans = max(ans, suffPos[i + 1] - prefPos[i]);
  	}
  	cout << ans;

    return 0;
}