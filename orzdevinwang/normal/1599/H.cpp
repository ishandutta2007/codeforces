#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
int get (int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int w;
	cin >> w;
	return w;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int Len = get (1, 1);
	int l = 1, r = 1e9, ns = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(get(1, mid) + (mid - 1) == Len) ns = mid, l = mid + 1;
		else r = mid - 1; 
	}
	int sx = Len + 2 - ns, sy = ns;
	int ex = 1e9 - get(1e9, sy), ey = 1e9 - get(sx, 1e9);
	cout << "! " << sx << ' ' << sy << ' ' << ex << ' ' << ey << endl;
	return 0;
}