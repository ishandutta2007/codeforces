#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int n, ls[N], use[N], op;
ll a[N], b[N];
int main() {  
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], a[i] += a[i - 1];
	L(i, 1, n) cin >> b[i], b[i] += b[i - 1];
	if(a[n] > b[n]) {
		L(i, 1, n) swap(a[i], b[i]);
		op = true;
	}
	L(i, 0, n - 1) use[i] = -1;
	int jly = 0;
	L(i, 0, n) {
		while(jly < n && b[jly + 1] <= a[i]) ++jly;
		ls[i] = jly;
		int v = a[i] - b[jly];
		if(use[v] != -1) {
			int o = use[v]; 
			if(op) {
				cout << jly - ls[o] << '\n';
				L(j, ls[o] + 1, jly) cout << j << ' ';
				cout << '\n' << i - o << '\n';
				L(j, o + 1, i) cout << j << ' ';
				cout << '\n';
			}
			else {
				cout << i - o << '\n';
				L(j, o + 1, i) cout << j << ' ';
				cout << '\n' << jly - ls[o] << '\n';
				L(j, ls[o] + 1, jly) cout << j << ' ';
				cout << '\n';
			}
			return 0;
		}
		use[v] = i;
	} 
	assert(0);
	return 0;
}