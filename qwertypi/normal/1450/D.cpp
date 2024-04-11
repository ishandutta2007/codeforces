#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[300000];
int ans[300001];
vector<vector<int>> inv(300001);
set<int> S;
void sub(){
	S.clear();
	int n;
	cin >> n;
	S.insert(-1);
	S.insert(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i <= n; i++){
		inv[i].clear();
	}
	
	for(int i = 0; i < n; i++){
		inv[A[i]].push_back(i);
	}
	
	bool failed = false;
	int lower = 0, upper = (1 << 30);
	for(int i = 1; i <= n; i++){
		if(inv[i].size() == 0){
			failed = true;
		}else{
			// for(auto i : inv[i]) cout << i << endl;
			lower = max(lower, 1 + inv[i][inv[i].size() - 1] - inv[i][0]);
			int max_sz = 0;
			for(int j = 0; j < inv[i].size(); j++){
				int sz = *S.upper_bound(inv[i][j]) - *--S.lower_bound(inv[i][j]) - 1;
				max_sz = max(max_sz, sz);
			}
			upper = min(upper, max_sz);
		}
		
		// cout << lower << ' ' << upper << endl;
		for(auto j : inv[i]){
			S.insert(j);
		}
		if(failed){
			ans[n + 1 - i] = 0;
		}else{
			if(lower <= n + 1 - i && n + 1 - i <= upper){
				ans[n + 1 - i] = 1;
			}else{
				ans[n + 1 - i] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i];
	}
	cout << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}