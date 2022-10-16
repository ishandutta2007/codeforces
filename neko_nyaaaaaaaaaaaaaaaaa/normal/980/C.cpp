#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> col(300, 10000);
	
	for (int i = 0; i < n; i++) {
		if (col[a[i]] != 10000) {a[i] = col[a[i]]; continue;}
		
		int ans = a[i];
		for (int j = max(0, a[i]-k+1); j < a[i]; j++) {
			if (col[j] == 10000 || a[i] - col[j] < k) {
				ans = j; break;
			}
		} 
		
		int tmp = ans;
		for (int j = tmp; j <= a[i]; j++) {
			if (col[ans] != 10000) {ans = col[tmp];}
			col[j] = ans;
		}
		
		a[i] = col[a[i]];
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	return 0;
}