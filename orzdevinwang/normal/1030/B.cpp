#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, d;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> d;
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		if(x + y >= d && x + y <= n * 2 - d && x - y <= d && y - x <= d) 
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}