#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 10), mod = 1e9 + 7 ;
int n, m;
char s[N][N]; 
void Main () {
	cin >> n >> m;
	L(i, 1, n) cin >> (s[i] + 1);
	int ns = 1e9, cnt = 0;
	L(i, 1, n) L(j, 1, m) 
		if(s[i][j] == 'A') 
			ns = min(ns, 4 - (i == 1 || i == n) - (j == 1 || j == m)), cnt += 1;
	if(cnt == n * m) return cout << 0 << '\n', void ();
	if(ns > 10) return cout << "MORTAL\n", void (); 
	L(i, 1, n) {
		cnt = 0;
		L(j, 1, m) cnt += s[i][j] == 'A';
		if(cnt == m) ns = min(ns, 2 - (i == 1 || i == n));
	}
	L(j, 1, m) {
		cnt = 0;
		L(i, 1, n) cnt += s[i][j] == 'A';
		if(cnt == n) ns = min(ns, 2 - (j == 1 || j == m));
	}
	cout << ns << '\n';
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}