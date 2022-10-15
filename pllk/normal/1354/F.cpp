#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define INF 999999999999999LL

int n, k;
ll aa[100], bb[100], ww[100];
int tt;

int dv[100][100][100];
ll dd[100][100][100];
int dt[100][100][100];

ll calc(int a, int b, int c) {
	if (a == 0 && b == 0) return 0;
	if (a == 0 || b < 0) return -INF;
	if (dv[a][b][c] == tt) return dd[a][b][c];
	if (a == c) {
		ll d = calc(a-1,b,c)+aa[a]+(k-1)*bb[a];
		dd[a][b][c] = d;
		dt[a][b][c] = 3;
	} else {
		ll d1 = calc(a-1,b,c)+(k-1)*bb[a];
		ll d2 = calc(a-1,b-1,c)+aa[a]+(b-1)*bb[a];
		if (d1 >= d2) {
			dd[a][b][c] = d1;
			dt[a][b][c] = 1;
		} else {
			dd[a][b][c] = d2;
			dt[a][b][c] = 2;
		}
	}
	dv[a][b][c] = tt;
	return dd[a][b][c];
}

void lol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> aa[i] >> bb[i];
		ww[i] = i;
	}
	// bubble sort ftw
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n-1; j++) {
			if (bb[j] > bb[j+1]) {
				swap(aa[j],aa[j+1]);
				swap(bb[j],bb[j+1]);
				swap(ww[j],ww[j+1]);
			}
		}
	}
	ll pp = 0;
	int pi = 0;
	for (int i = 1; i <= n; i++) {
		ll uu = calc(n,k-1,i);
		if (uu >= pp) {
			pp = uu;
			pi = i;
		}
	}
	vector<int> v1, v2;
	int ak = k;
	k--;
	while (n >= 1) {
		if (dt[n][k][pi] == 1) {
			if (ak != 1) v1.push_back(ww[n]);
			n--;
		} else if (dt[n][k][pi] == 2) {
			v2.push_back(ww[n]);
			n--; k--;
		} else if (dt[n][k][pi] == 3) {
			n--;
		}
	}
	reverse(v2.begin(),v2.end());
	cout << v1.size()*2+v2.size()+1 << "\n";
	for (auto x : v2) cout << x << " ";
	for (auto x : v1) cout << x << " " << -x << " ";
	cout << ww[pi] << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		tt = i;
		lol();
	}
}