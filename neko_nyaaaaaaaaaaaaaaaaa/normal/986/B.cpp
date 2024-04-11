#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k = 0;
vector<int> a(1000002);
vector<int> c(1000002);

void dfs(int u) {
	k++;
	c[u] = 1;
	if (a[u] != u && c[a[u]] == 0) {dfs(a[u]);}
}

int main() {
	ios::sync_with_stdio(0);	
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i]) continue;
		k = 0; dfs(i);
		ans += (k-1);
		ans %= 2;
      	if (ans < 0) {ans += 2;}
	}
	
	if (n % 2 == ans % 2) cout << "Petr";
	else cout << "Um_nik";

	return 0;
}