#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 6007;
int n, m, x[N], y[N], v[3][2], w[N][4][4][4];
ll cal1 () { // 0; 0; 0; 
	ll res = 0;
	L(i, 1, n) { 
		v[0][0] = x[i] & 3, v[0][1] = y[i] & 3;
		for(int l1 = 0; l1 < 4; l1 += 2) 
			for(int l2 = 0; l2 < 4; l2 += 2) 
				for(int l3 = 0; l3 < 4; l3 += 2) L(a, 0, 3) L(b, 0, 3) L(c, 0, 3) L(d, 0, 3) {
					v[1][0] = a, v[1][1] = b;
					v[2][0] = c, v[2][1] = d;
					int all = 0;
					L(i, 0, 2) all += v[i][0] * v[(i + 1) % 3][1] - v[i][1] * v[(i + 1) % 3][0];
					if ((__gcd (a - c + 4, b - d + 4) & 3) != l3) continue;
					if (all & 1) continue; 
					all -= l1 + l2 + l3; 
					if (all & 3) continue; 
					
					if(a == c && b == d && l1 == l2) 
						res += w[i][a][b][l1] * (w[i][c][d][l2] - 1);
					else 
						res += w[i][a][b][l1] * w[i][c][d][l2];
				}
	}
	return res;
}
ll cal2 () { // 1; 1; 0; 
	ll res = 0;
	L(i, 1, n) { 
		v[0][0] = x[i] & 3, v[0][1] = y[i] & 3;
		for(int l1 = 1; l1 < 4; l1 += 2) 
			for(int l2 = 1; l2 < 4; l2 += 2) 
				for(int l3 = 0; l3 < 4; l3 += 2) L(a, 0, 3) L(b, 0, 3) L(c, 0, 3) L(d, 0, 3) {
					v[1][0] = a, v[1][1] = b;
					v[2][0] = c, v[2][1] = d;
					int all = 0;
					L(i, 0, 2) all += v[i][0] * v[(i + 1) % 3][1] - v[i][1] * v[(i + 1) % 3][0];
					if (all & 1) continue; 
					all -= l1 + l2 + l3; 
					if ((__gcd (a - c + 4, b - d + 4) & 3) != l3) continue;
					if (all & 3) continue; 
					if(a == c && b == d && l1 == l2) 
						res += w[i][a][b][l1] * (w[i][c][d][l2] - 1);
					else 
						res += w[i][a][b][l1] * w[i][c][d][l2];
				}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) 
		cin >> x[i] >> y[i]; 
	L(i, 1, n) {
		L(j, i + 1, n) {
			int qi = __gcd (abs (x[i] - x[j]), abs (y[i] - y[j])) & 3;
			w[i][x[j] & 3][y[j] & 3][qi & 3] += 1;
			w[j][x[i] & 3][y[i] & 3][qi & 3] += 1;
		}
	}
	cout << cal1 () / 6 + cal2 () / 2 << "\n";
	return 0; // a = S - b / 2 + 1
}