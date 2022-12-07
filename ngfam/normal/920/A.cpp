#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		vector < int > w;
		while(k--){
			int x;
			cin >> x;
			w.push_back(x);
		}
		int ans = 1;
		for(int i = 1; i <= n; ++i){
			int best = 1e9;
			for(int x : w){
				best = min(best, abs(x - i) + 1);
			}
			ans = max(ans, best);
		}
		cout << ans << endl;
	}

	return 0;
}