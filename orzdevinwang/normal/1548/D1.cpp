#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 1e5 + 7;
int n, x[N], y[N], cnt[2][2];
int w[3][2] ;
bool chk () {
	int c = 0;
	L(i, 0, 2) L(j, i + 1, 2) if(w[i][0] == w[j][0] && w[i][1] == w[j][1]) c ++;
	return c % 2 == 0; 
} 
ll ns = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> x[i] >> y[i];
		x[i] /= 2, y[i] /= 2;
		cnt[x[i] & 1][y[i] & 1]++;
	}
	L(a, 0, 3) L(b, 0, 3) L(c, 0, 3) L(d, 0, 3) if(a + b + c + d == 3) {
		int tp = 0;
		L(i, 1, a) w[tp][0] = 0, w[tp][1] = 0, tp++;
		L(i, 1, b) w[tp][0] = 0, w[tp][1] = 1, tp++;
		L(i, 1, c) w[tp][0] = 1, w[tp][1] = 0, tp++;
		L(i, 1, d) w[tp][0] = 1, w[tp][1] = 1, tp++;
		if(chk()) continue; 
		
		ll res = 1;
		L(i, 0, a - 1) res *= cnt[0][0] - i;
		L(i, 1, a) res /= i;
		
		L(i, 0, b - 1) res *= cnt[0][1] - i;
		L(i, 1, b) res /= i;
		
		L(i, 0, c - 1) res *= cnt[1][0] - i;
		L(i, 1, c) res /= i;
		
		L(i, 0, d - 1) res *= cnt[1][1] - i;
		L(i, 1, d) res /= i;
		
		ns += res;
	} 
	cout << ns << "\n";
	return 0;
}