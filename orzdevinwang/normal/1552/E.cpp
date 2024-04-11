#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e4 + 7;
int n, k, c[N], tp, a[N], b[N], lst[N];
bool vis[N];
void calc (int l, int r) {
	L(i, 1, n * k) if(l <= c[i] && c[i] <= r && vis[c[i]] == false) {
		if(lst[c[i]]) {
			a[c[i]] = lst[c[i]], b[c[i]] = i;
			L(j, 1, n) lst[j] = 0;
			vis[c[i]] = true;
			continue;
		}
		lst[c[i]] = i;
	}
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> k;
	L(i, 1, n * k) cin >> c[i];
	int z = k - 1;
	L(i, 1, (n + z - 1) / z) calc ((i - 1) * z + 1, min(i * z, n));
	L(i, 1, n) cout << a[i] << ' ' << b[i] << '\n';
	return 0;
}