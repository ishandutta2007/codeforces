#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[100001], prec[100001];

int sum(int l, int r){
	return prec[r + 1] ^ prec[l];
}

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		prec[i + 1] = prec[i] ^ A[i];
	}
	
	int ans = (1 << 30);
	for(int i = 0; i < n; i++){
		vector<pair<int, int>> W, M;
		for(int j = i - 1; j >= max(0LL, i - 100); j--){
			W.push_back({sum(j, i - 1), i - j});
		}
		for(int j = i; j <= min(n - 1, i + 100); j++){
			M.push_back({sum(i, j), j - i + 1});
		}
		
		sort(W.begin(), W.end(), [](pair<int, int> a, pair<int, int> b){
			return a.first > b.first;
		});
		
		W.push_back({-(1 << 30), (1 << 30)});
		sort(M.begin(), M.end(), [](pair<int, int> a, pair<int, int> b){
			return a.first > b.first;
		});
		
		M.push_back({-(1 << 30), (1 << 30)});
		
// 		cout << "******" << endl;
// 		for(auto i : W){
// 			cout << i.first << ' ' << i.second << endl;
// 		}
		
// 		for(auto i : M){
// 			cout << i.first << ' ' << i.second << endl;
// 		}
		
		int l = 0, r = 0;
		int best = 1 << 30;
		while(l != W.size() - 1 || r != M.size() - 1){
			// cout << l << ' ' << r << endl;
			if(W[l].first > M[r].first){
				best = min(best, W[l++].second);
			}else{
				ans = min(ans, best + M[r++].second);
			}
		}
	}
	
	if(ans >= (1 << 30)){
		cout << -1 << endl;
	}else{
		cout << ans - 2 << endl;
	}
}