#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, a[N];
char s[N];
bool vis[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> (s + 1);
	L(i, 1, n) a[i] = s[i] - '0', a[i] += a[i - 1];
	if(a[n] == 0) return cout << "YES\n", 0;
//	cout << a[n] << '\n';
	L(w, 1, a[n] - 1) if(a[n] % w == 0) {
		memset(vis, 0, sizeof(vis));
		vis[0] = true;
		L(j, 1, n) L(i, 0, j - 1) if(a[j] - a[i] == w) 
			vis[j] |= vis[i];
		if(vis[n]) return cout << "YES\n", 0;
	}
	cout << "NO\n";
	return 0;
}