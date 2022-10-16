#include <bits/stdc++.h>
using namespace std;

int main() {
      
      ios_base::sync_with_stdio(0); cin.tie(NULL);
      
	long n, k;
	cin >> n >> k;
	int a, b, c, d;
	vector<int> count;
	bool ans = false;
	if (n == 1) {
		ans = true;
		for (int i = 0; i < k; i++) {
			cin >> a;
			if (a == 1) {ans = false; break;}
		}
	} else {
		for (long i = 0; i < n; i++) {
			b = 0;
			for (long j = 0; j < k; j++) {
				cin >> a;
				if (a == 1) {b += pow(2, j);} 
			}
			int s = 0;
			bool check = false;
			while (s < count.size()) {
				if ((count[s] & b) == 0) {ans = true; break;}
				else if (count[s] == b) {check = true; break;}
				s++;
			}
			if (!check) {count.push_back(b);}
			if (ans) break;
		} 
	}
	if (ans == true) cout << "YES";
	else cout << "NO";
	
	
	return 0;
}