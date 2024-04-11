#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
int l, r, f[10];
int query (int d) {
	cout << "? " << (200 / d) * 200 << " ";
	L(i, 1, 200 / d) L(j, 1, 200) cout << i * d << " " << j << " ";
	cout << endl;
	int w;
	cin >> w;
	return w;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	f[0] = query (1);
	int l = 1, r = 7, p = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		f[mid] = query (1 << mid);
		if(f[0] == f[mid] * (1 << mid)) 
			p = mid, l = mid + 1;
		else 
			r = mid - 1;
	}
	int R = abs (f[p] - f[p + 1] * 2);
	cout << "! " << (f[0] / R + R - 2) * 2 << '\n';
	return 0;
}