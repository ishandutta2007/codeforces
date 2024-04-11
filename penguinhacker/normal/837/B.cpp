#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[100];

bool check(int a, int b, int c, int d) { //[a, b], then [c, d]
	char compare = s[a][c];
	for (int i=a; i<=b; ++i)
		for (int j=c; j<=d; ++j)
			if (s[i][j] != compare)
				return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	
	bool pos = 0;
	if (n%3==0) {
		set<char> colors;
		for (int i=0; i<3; ++i)
			if (check(i*n/3, (i+1)*n/3-1, 0, m-1))
				colors.insert(s[i*n/3][0]);
		if (colors.size() == 3)
			pos = 1;
	}
	if (m%3==0) {
		set<char> colors;
		for (int i=0; i<3; ++i)
			if (check(0, n-1, i*m/3, (i+1)*m/3-1))
				colors.insert(s[0][i*m/3]);
		if (colors.size() == 3)
			pos = 1;
	}

	cout << (pos?"YES":"NO");
	return 0;
}