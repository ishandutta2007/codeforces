#include <bits/stdc++.h>


using namespace std;

int A[300010];
int occur[300010];
int best[300010];

set<int> S;
vector<pair<int, int>> vp;

int n;
void update(int val, int idx){
//	cout << "UPD:" << val << ' ' << occur[val] << ' ' << idx << endl; 
	if(occur[val] == -1 && idx == n){
		best[val] = (1 << 30);
	}else if(occur[val] == -1){
		best[val] = max(best[val], idx + 1);
	}else if(idx == n){
		best[val] = max(best[val], n - occur[val]);
	}else{
		best[val] = max(best[val], idx - occur[val]);
	}
	occur[val] = idx;
}

void sub(){
	S.clear();
	vp.clear();
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		S.insert(A[i]);
	}
	for(auto i : S){
		occur[i] = -1;
		best[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		update(A[i], i);
	}
	
	for(auto i : S){
		update(i, n);
	}
	for(auto i : S){
		vp.push_back({best[i], i});
	}
	
	sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b){
		return a.first < b.first;
	});
//	for(auto i : vp){
//		cout << i.first << ' ' << i.second << endl;
//	}
	int idx = 0, _min = (1 << 30);
	for(int i = 1; i <= n; i++){
		while(idx < vp.size() && vp[idx].first <= i){
			_min = min(_min, vp[idx].second);
			idx++;
		}
		
		if(_min == (1 << 30)){
			cout << -1 << ' ';
		} else{
			cout << _min << ' ';
		}
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