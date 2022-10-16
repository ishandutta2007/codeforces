#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << '.';
	}
	cout << '\n';
	
	vector<string> s(2);
	for (int i = 0; i < n; i++) {
		s[0] += '.';
		s[1] += '.';
	}
	
	if (k % 2 == 0) {
		for (int i = 1; 2*i <= k; i++) {
			s[0][i] = '#';
			s[1][i] = '#';
		}
	} else {
		int mid = n/2;
		s[0][mid] = '#';
		k--;
		int pt1 = mid - 1, pt2 = mid + 1;
		for (; pt1 && k > 0; pt1--, pt2++) {
			s[0][pt1] = '#';
			s[0][pt2] = '#';
			k -= 2;
		}
		
		if (k > 0) {
			pt1 = mid - 1, pt2 = mid + 1;
			for (; pt1 && k > 0; pt1--, pt2++) {
				s[1][pt1] = '#';
				s[1][pt2] = '#';
				k -= 2;
			}
		}
	}
	cout << s[0] << '\n' << s[1] << '\n';
	for (int i = 0; i < n; i++) {
		cout << '.';
	}
	
	return 0;
}