#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int m, s;
	cin >> m >> s;
	if (s == 0) {
	      if (m == 1) {cout << "0 0"; return 0;}
	      else {cout << "-1 -1"; return 0;}
	}
	vector<int> a(m, 0), b(m, 0);
	if (s > 9*m) {cout << "-1 -1"; return 0;}
	int i = 0;
	for (; 9*(i+1) <= s; i++) {
	      a[i] = 9;
	}
	if (i < m) {
	      a[i] = s - 9*i;
	}
	s--;
	b[0] = 1;
	i = m-1;
	while (s >= 9) {
	      b[i] = 9;
	      s -= 9;
	      i--;
	}
	b[i] += s;
	for (i = 0; i < b.size(); i++) {
	      cout << b[i];
	}
	cout << " ";
	for (i = 0; i < a.size(); i++) {
	      cout << a[i];
	}
	
	return 0;
}