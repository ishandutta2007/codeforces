#include<bits/stdc++.h>
#include<windows.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 11);
int n, ns[N], w[N][N], os[N][N], r[N / 2];
bitset < N / 2 > c[3][N];
int val[N];
char s[N][N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	if(n & 1) return cout << "NONE\n", 0;
	int cnt = 0;
	L(i, 0, n - 1) c[0][i].set (i >> 1), w[0][i] = i >> 1;
	L(i, 0, n / 2 - 1) val[i] = -1;
	L(i, 0, n - 2) {
		int o = i % 3;
		L(j, 0, n - 1) {
			c[(o + 1) % 3][j] = c[o][j];
			if(j > 0) c[(o + 1) % 3][j] ^= c[o][j] ^ c[o][j - 1], os[i + 1][j] ^= os[i][j] ^ os[i][j - 1] ^ 1;
			if(j < n - 1) c[(o + 1) % 3][j] ^= c[o][j] ^ c[o][j + 1], os[i + 1][j] ^= os[i][j] ^ os[i][j + 1] ^ 1;
			if(i > 0) c[(o + 1) % 3][j] ^= c[o][j] ^ c[(o + 2) % 3][j], os[i + 1][j] ^= os[i][j] ^ os[i - 1][j] ^ 1;
			w[i + 1][j] = c[(o + 1) % 3][j]._Find_first();
			os[i + 1][j] ^= os[i][j] ^ 1;
		}
	}
	L(i, 0, n - 1) 
		cin >> s[i];
	L(i, 0, n - 1) {
		L(j, 0, n - 1) {
			if(s[i][j] != '.') {
				int x = (s[i][j] == 'S') ^ os[i][j];
				if(val[w[i][j]] == (x ^ 1)) return cout << "NONE\n", 0;
				val[w[i][j]] = x;
			}
		}
	}
	L(i, 0, n / 2 - 1) 
		if(val[i] == -1) 
			return cout << "MULTIPLE\n", 0;
	cout << "UNIQUE\n";
	L(i, 0, n - 1) {
		L(j, 0, n - 1) {
			cout << ((val[w[i][j]] ^ os[i][j]) ? 'S' : 'G');
		}
		cout << '\n';
	}
//	L(i, 0, n - 1) {
//		L(j, 0, n - 1) {
//			cout << i << " " << j << " : ";
//			L(k, 0, n - 1) if(k % 2 == 0) {
//				cout << (bool) c[i][j][k];
//			}
//			cout << " is " << (bool) c[i + 1][j][n] << '\n';
//		}
//	}
	return 0;
}
/*
......##....
.####.##.##.
.#..#....##.
.#..#####...
.###....#.##
...#.##.#.##
##.#.##.#...
##.#....###.
...#####..#.
.##....#..#.
.##.##.####.
....##......
*/