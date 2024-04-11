#include <bits/stdc++.h>
using namespace std;

int r, c;
string s[9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i=0; i<9; ++i) {
		for (int j=0; j<3; ++j) {
			string temp;
			cin >> temp;
			s[i] += temp;
		}
	}
	cin >> r >> c, r--, c--;
	int R=r%3, C=c%3;
	
	bool pos = 0;
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			if (s[3*R+i][3*C+j]=='.') {
				s[3*R+i][3*C+j] = '!';
				pos = 1;
			}
		}
	}
	if (!pos) {
		for (int i=0; i<9; ++i)
			for (int j=0; j<9; ++j)
				if (s[i][j]=='.')
					s[i][j] = '!';
	}
	
	for (int a=0; a<3; ++a) {
		for (int b=0; b<3; ++b) {
			for (int c=0; c<3; ++c) {
				for (int d=0; d<3; ++d) {
					cout << s[3*a+b][3*c+d];
				}
				cout << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}