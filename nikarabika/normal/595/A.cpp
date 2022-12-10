#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			bool khab = false;
			for(int k = 0; k < 2; k++){
				int x;
				cin >> x;
				khab |= x;
			}
			ans += khab;
		}
	}
	cout << ans << endl;
}