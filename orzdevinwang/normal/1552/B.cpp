#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e5 + 7;
int n, dp[N], r[N][6];
void Main () {
	cin >> n;
	L(i, 1, n) L(j, 1, 5) cin >> r[i][j];
	int best = 1;
	L(i, 2, n) {
		int cnt = 0;
		L(j, 1, 5) cnt += r[i][j] < r[best][j];
		if(cnt >= 3) 
			best = i;
	}
	L(i, 1, n) if(i != best) {
		int cnt = 0;
		L(j, 1, 5) cnt += r[i][j] < r[best][j];
		if(cnt >= 3) 
			return cout << "-1\n", void();
	}
	cout << best << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}