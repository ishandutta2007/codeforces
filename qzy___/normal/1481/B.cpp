#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		int n , k;
		int h[110];
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> h[i];
		int ans = -1;
		while(k > 0) {
			int flag = false;
			for(int i = 1; i < n; i++)
				if(h[i] < h[i + 1]) {
					k-- , h[i]++;
					if(k <= 0)
						ans = i;
					flag = true;
					break;
				}
			if(flag == false) break;
		}
		cout << ans << endl;
	}
}