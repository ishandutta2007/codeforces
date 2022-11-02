#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e9 + 7;


void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	int a[n], b[m];
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < m;i++) cin >> b[i];
	int id1 = 0, id2 = 0;
	while(a[id1] % p == 0) id1++;
	while(b[id2] % p == 0) id2++;
	cout << id1 + id2 << '\n';
}

int main() {

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	solve();
}