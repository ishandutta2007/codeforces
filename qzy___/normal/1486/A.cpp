#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T , n;
long long h[110];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> h[i];
		int flag = false;
		for(int i = 1; i < n; i++) {
			if(h[i] < i - 1) {flag = true; break;}
			h[i + 1] += h[i] - i + 1 , h[i] = i - 1;
		}
		for(int i = 1; i < n; i++) if(h[i] >= h[i + 1]) flag = true;
		if(flag == true) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}