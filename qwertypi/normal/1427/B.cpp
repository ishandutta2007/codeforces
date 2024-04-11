#include <bits/stdc++.h>

using namespace std;

char A[200000];
void sub(){
	int n, k;
	cin >> n >> k;
	cin >> A;
	bool all_F = true;
	for(int i = 0; i < n; i++){
		if(A[i] == 'W'){
			all_F = false;
		}
	}
	
	if(all_F){
		if(k == 0){
			cout << 0 << endl;
		}else{
			cout << 2 * min(k, n) - 1 << endl;
		}
		return;
	}
	
	bool yes = false;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(A[i] == 'W'){
			ans += 1 + (i != 0 && A[i - 1] == 'W');
		}
	}
	int prev = -1;
	vector<int> dis, edge;
	for(int i = 0; i < n; i++){
		if(A[i] == 'W'){
			if(prev == -1){
				edge.push_back(i - prev - 1);
			}else{
				dis.push_back(i - prev - 1);
			}
			prev = i;
		}
	}
	edge.push_back(n - prev - 1);
	sort(dis.begin(), dis.end());
	
	for(int i = 0; i < dis.size() && k != 0; i++){
		if(dis[i] == 0) continue;
		if(k >= dis[i]){
			ans += dis[i] * 2 + 1;
			k -= dis[i];
		}else{
			ans += k * 2;
			k = 0;
		}
	}
	
	for(int i = 0; i < edge.size() && k != 0; i++){
		if(k >= edge[i]){
			ans += edge[i] * 2;
			k -= edge[i];
		}else{
			ans += k * 2;
			k = 0;
		}
	}

	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}