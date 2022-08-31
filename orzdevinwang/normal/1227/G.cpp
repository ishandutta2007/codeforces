#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1007;
int n, a[N];
bool s[N][N];
int f[N], siz[N], tp;
int main() {
	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n, siz[1] = n + 1;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n + 1) f[i] = 1;
	L(i, 1, n) L(j, 1, i) if(siz[j] > 1) {
		int x = 0, y = 0;
		L(k, 1, n + 1) if(f[k] == j) {
			if(!x) x = k; 
			else y = k;
		}
		s[x][i] = true, --a[i], f[x] = i + 1, --siz[j], ++siz[i + 1];
		L(k, 1, n + 1) if(k != x && k != y && a[i]) { 
			s[k][i] = true, --a[i];
			if(f[k] == j) f[k] = i + 1, --siz[j], ++siz[i + 1];
		}
		break;
	}
	cout << n + 1 << "\n";
	L(i, 1, n + 1) {
		L(j, 1, n) cout << s[i][j];
		cout << "\n";
	}
	return 0;
}