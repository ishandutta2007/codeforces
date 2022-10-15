#include<bits/stdc++.h>
using namespace std;
#define sz(v) (int) v.size()
#define all(v) v.begin(),v.end()
#define in freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define ios  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007
 
int main() {
 ios
	int n, m;
	cin >> n >> m;
	int r[1000], c[1000];
	int ans = 0;
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
 
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		r[x] = c[y] = 1;
	}
 
	ans -= (n % 2 == 1 && r[n / 2] == 0 && c[n / 2] == 0);
 
	for (int i = 1; i < n - 1; i++) {
		if (r[i] == 0) {
			ans++;
		}
		if (c[i] == 0) {
			ans++;
		}
	}
 
	cout << ans << endl;
 
	return 0;
}