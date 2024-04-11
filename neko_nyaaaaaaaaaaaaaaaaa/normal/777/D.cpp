#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	int n;
	cin >> n;
	vector<string> a(n), ans(n);
	for (int i = 0; i < n; i++) {
	      cin >> a[i];
	      ans[i] += '#';
	}
	ans[n-1] = a[n-1];
	for (int i = n-2; i >= 0; i--) {
	      if (a[i][1] > ans[i+1][1]) {break;}
	      int pt = 1;
	      while (pt < ans[i+1].size()) {
	            if (a[i][pt] == ans[i+1][pt]) {
	                  ans[i] += a[i][pt];
	                  pt++;
	            } else if (a[i][pt] < ans[i+1][pt]) {
	                  ans[i] = a[i];
	                  break;
	            } else break;
	      }
	}
	for (int i = 0; i < n; i++) {
	      cout << ans[i] << endl;
	}
	
}