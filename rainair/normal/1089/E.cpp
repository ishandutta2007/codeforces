#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int n;
string s[10] = {"a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 b7 c7 d7 e7 f7 g7 g8 f8 h8",
				"a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 b7 c7 d7 e7 f7 g7 g8 f8 e8 h8",
				"a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 b7 c7 d7 e7 f7 g7 g8 f8 e8 d8 h8",
				"a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 b7 c7 d7 e7 f7 g7 g8 f8 e8 d8 c8 h8",
				"a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 b7 c7 d7 e7 f7 g7 g8 f8 e8 d8 c8 b8 h8",
				"a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 b7 c7 d7 e7 f7 g7 g8 f8 e8 d8 c8 b8 a8 h8",
				"a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 c7 d7 e7 f7 g7 h7 b7 b8 a8 c8 d8 e8 f8 g8 h8"};

void print(int x, int y) {
	printf(" %c%c", x - 1 + 'a', y + '0');
}

int main() {
	scanf("%d", &n);
	if (n <= 56) {
		n -= 2;
		printf("a1");
		int x = 1, y = 1;
		for (int i = 1; i <= n; i++) {
			if (y & 1) {
				if (x == 8) y++;
				else x++;
			} else {
				if (x == 1) y++;
				else x--;
			}
			print(x, y);
		}
		print(x, n % 16 == 7 || n % 16 == 8 ? 7 : 8);
		puts(" h8");
	} else {
		cout << s[n - 57] << endl;
	}
	return 0;
}