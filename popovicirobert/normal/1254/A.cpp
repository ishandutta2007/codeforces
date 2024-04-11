#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

const int MAXN = 100;

char mat[MAXN + 1][MAXN + 1];
int sol[MAXN + 1][MAXN + 1];
  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
	int t, i, j, n, m, k;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);

	cin >> t;

	while(t--) {
		cin >> n >> m >> k;

		int cnt = 0;
		for(i = 1; i <= n; i++) {
			cin >> (mat[i] + 1);
			for(j = 1; j <= m; j++) {
				cnt += (mat[i][j] == 'R');
				sol[i][j] = -1;
			}
		}

		auto get = [&](int x) -> char {
			if(x < 26) return (char)('a' + x);
			if(x < 52) return (char)('A' + x - 26);
			return (char)(x - 52 + '0');
		};
	
		int base = cnt / k, rem = cnt % k;

		int l = 1, c = 1;
		int dir = 1, id = 0;

		while(l <= n && id < k) {
			int need = base + (rem > 0);
			rem--;

			while(need > 0) {
				sol[l][c] = id;
				if(mat[l][c] == 'R') {
					need--;
				}

				if(dir == 1) {
					c++;
					if(c == m + 1) {
						dir *= -1;
						l++, c = m;
					}
				}
				else {
					c--;
					if(c == 0) {
						dir *= -1;
						l++, c = 1;
					}
				}
			}
			id++;
		}

		id--;
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				if(sol[i][j] == -1) {
					sol[i][j] = id;
				}
				cout << get(sol[i][j]);
			}
			cout << "\n";
		}
	}
		
	return 0;
}