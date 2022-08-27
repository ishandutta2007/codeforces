#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e6 + 7; 
int n, p[N], nx[N], w[N], tp;
bool vis[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) {
		cout << "? ";
		L(j, 1, n) cout << 1 + (j == i) << ' ';
		cout << endl;
		int r;
		cin >> r;
		if(r && r != i) nx[i] = r;
	}
	L(i, 1, n) {
		cout << "? ";
		L(j, 1, n) cout << 1 + (j != i) << ' ';
		cout << endl;
		int r;
		cin >> r;
		if(r && r != i) nx[r] = i;
	}
//	L(i, 1, n) cout << nx[i] << ' ';
//	cout << '\n';
	L(i, 1, n) vis[nx[i]] = 1;
	int fir = -1;
	L(i, 1, n) if(!vis[i]) fir = i;
	cout << "! ";
	while (fir) {
		w[fir] = ++tp;
		fir = nx[fir];
	}
	L(i, 1, n) cout << w[i] << ' ';
	cout << endl;
	return 0;
}