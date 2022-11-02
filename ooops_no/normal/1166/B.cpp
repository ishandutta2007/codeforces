#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
#include <numeric> 
using namespace std;

#define int long long
#define pb push_back

vector<char> v{ 'a', 'e', 'i', 'o', 'u' };
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, ii, jj;
	cin >> n;
	bool x = 0;
	for (int i = sqrt(n); i >= 2; i--) {
		if (n % i == 0 && i >= 5 && n / i >= 5) {
			x = 1;
			ii = i, jj = n / i;
			break;
		}
	}
	if (x) {
		for (int i = 0; i < ii; i++) {
			for (int j = 0; j < jj; j++) {
				cout << v[(i + j) % 5];
			}
		}
	}
	else {
		cout << -1;
	}
}