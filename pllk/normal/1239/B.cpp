#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
int d[606060];
int s0[606060];
int s1[606060];
int s2[606060];
int f[606060];

int c0(int a, int b) {
	return s0[b]-s0[a-1];
}

int c1(int a, int b) {
	return s1[b]-s1[a-1];
}

int c2(int a, int b) {
	return s2[b]-s2[a-1];
}

int main() {
	cin >> n;
	cin >> s;
	s = "#"+s+s;
	int p = 0;
	vector<int> v;
	int c = 0;
	for (int i = 1; i <= 2*n; i++) {
		if (s[i] == '(') {
			c++;
			v.push_back(i);
		} else {
			c--;
			if (v.size()) {
				f[v[v.size()-1]] = i;
				v.pop_back();
			}
		}
		d[i] = c;
		if (c < p) p = c;
	}
	if (c != 0) {
		cout << "0\n";
		cout << "1 1\n";
		return 0;
	}
	for (int i = 1; i <= 2*n; i++) {
		d[i] -= p;
		s0[i] = s0[i-1]+(s[i] == ')' && d[i] == 0);
		s1[i] = s1[i-1]+(s[i] == ')' && d[i] == 1);
		s2[i] = s2[i-1]+(s[i] == ')' && d[i] == 2);
	}
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(' && d[i] == 1) k++;
	}
	int k1 = 1, k2 = 1;
	int r = k;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(' && d[i] == 1) {
			int a = i;
			int b = f[i];
			int u = k+c1(a+1,b-1)-c0(b+1,a-1+n);
			if (u > r) {
				r = u;
				k1 = a;
				k2 = b;
			}
		}
		if (s[i] == '(' && d[i] == 2) {
			int a = i;
			int b = f[i];
			int u = k+1+c2(a+1,b-1);
			if (u > r) {
				r = u;
				k1 = a;
				k2 = b;
			}
		}
	}
	if (k2 > n) k2 -= n;
	cout << r << "\n";
	cout << k1 << " " << k2 << "\n";
}