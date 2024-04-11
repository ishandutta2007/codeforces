#include <bits/stdc++.h>
 
using namespace std;
 
int cnt[200001];
int A[200001];
int ans[200001];
vector<vector<int>> in(200001);
void sub(){
	int n;
	cin >> n;
	fill(cnt + 0, cnt + n + 1, 0);
	for(int i = 1; i <= n; i++){
		in[i].clear();
	}
	for(int i = 0; i < n; i++){
		cin >> A[i];
		cnt[A[i]]++;
		in[A[i]].push_back(i);
	}
	
	int res = 0;
	for(int i = 1; i <= n; i++){
		res += cnt[i] >= 1;
	}
	cout << res << endl;
	int idx = 1;
	for(int i = 0; i < n; i++){
		ans[i] = A[i];
	}
	for(int i = 1; i <= n; i++){
		if(cnt[i] == 0){
			while(in[idx].size() <= 1) idx++;
			if(in[idx].back() + 1 == i){
			    //great
				ans[(int) in[idx][(int) in[idx].size() - 2]] = i;
				int v = in[idx].back();
				in[idx].pop_back();
				in[idx].pop_back();
				in[idx].push_back(v);
			}else{
				ans[in[idx].back()] = i;
				in[idx].pop_back();
			}
		}
	}
	int k = 0;
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	} 
	cout << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
	return 0;
}