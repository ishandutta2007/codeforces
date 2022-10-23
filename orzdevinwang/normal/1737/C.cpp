#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
using namespace std;
const int N = 1 << 20;
int n, vis[2][2];
int X[4], Y[4]; 
void Main() {
	cin >> n;
	me(vis, 0);
	int s = 0;
	L(i, 1, 3) {
		cin >> X[i] >> Y[i]; 
		vis[X[i] % 2][Y[i] % 2] = 1;
		s += min(X[i] - 1, n - X[i]);
		s += min(Y[i] - 1, n - Y[i]);
	}
	int x, y;
	cin >> x >> y;
	if(s == 2) {
		int cx = 0, cy = 0;
		L(i, 1, 3) {
			cx += x == X[i];
			cy += y == Y[i];
		}
//		cout << cx << ' ' << cy << endl;
		if(cx == 2 || cy == 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return ;
	}
	if(vis[x % 2][y % 2]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	
} 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}