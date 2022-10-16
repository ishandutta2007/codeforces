#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int c2(int n) {
      if (n == 0) return 0;
      return n*(n-1)/2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	int inv = 0;
	for (int i = 0; i < n; i++) {
	      cin >> a[i];
	      for (int j = 0; j < i; j++) {
	            if (a[i] < a[j]) {inv++;}
	      }
	}
	int m;
	cin >> m;
	while (m--) {
	      int x, y;
	      cin >> x >> y;
	      inv += c2(y - x + 1);
	      inv %= 2;
	      if (inv) {cout << "odd\n";}
	      else {cout << "even\n";}
	}
	
	
	
	return 0;
}