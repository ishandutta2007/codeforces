#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int n, m, a[N], b[N], p[N], ns = 1;
bool vis[N];
void Main() {
	ns = 1; 
	cin >> n;
	L(i, 1, n) cin >> a[i], vis[i] = false;
	L(i, 1, n) cin >> b[i], p[a[i]] = b[i];
	L(i, 1, n) if(!vis[i]) {
		int u = i;
		while(!vis[u]) vis[u] = true, u = p[u];
		ns = (ll) ns * 2 % mod;
	}
	cout << ns << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}