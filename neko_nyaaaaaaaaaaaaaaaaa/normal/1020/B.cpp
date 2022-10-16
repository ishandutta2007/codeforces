#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> a(1001);
vector<int> vis(1001);

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[j] = 0;
		}
		
		int x = i;
		while (1) {
			vis[x]++;
			if (vis[x] == 2) {cout << x << " "; break;}
			x = a[x];
		}
	}
	
	return 0;
}