#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;
int h;

int dv[55][55];
int dd[55][55];

int calc(int a, int b) {
	if (a >= b) return 0;
	if (dv[a][b] == h) return dd[a][b];
	int m = 0;
	m = max(m,calc(a,b-1));
	if (s[b] == ')') {
		for (int i = a; i < b; i++) {
			if (s[i] == '(') {
				m = max(m,2+calc(a,i-1)+calc(i+1,b-1));
			}
		}
	}
	dv[a][b] = h;
	dd[a][b] = m;
	return m;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		h++;
		cin >> n;
		cin >> s;
		s = "#"+s;
		int m = calc(1,n);
		cout << (n-m)/2 << "\n";
	}
}