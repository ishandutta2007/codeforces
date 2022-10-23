#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e5 + 7;
string a, b;
int vis[128];
void Main() {
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	me(vis, 0);
	int p = 0;
	for(auto u : b) {
		while(p < sz(a) && a[p] != u) vis[a[p] - 'A'] = true, ++p;
		if(p == sz(a) || vis[u - 'A']) {
			cout << "NO\n";
			return ;
		}
		++p;
	}
	cout << "YES\n";
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}