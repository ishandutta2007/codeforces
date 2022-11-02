#pragma optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int f(int x){
	int cnt = 0;
	while(~x & 1){
		cnt++, x >>= 1;
	}
	return cnt;
}

int32_t main(){
	int n;
	cin >> n;
	string s;
	map<int, vector<int>> A;
	set<int> ans;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		A[f(v)].push_back(v);
		ans.insert(v);
	}
	int _max = 0;
	int W = -1;
	for(int i = 0; i < A.size(); i++){
		if((long long)A[i].size() > _max){
			_max = (long long)A[i].size();
			W = i;
		}
	}
	for(auto i : A[W]){
		ans.erase(i);
	}
	cout << n - _max << endl;
	for(auto i : ans){
		cout << i << ' ';
	}
	return 0;
}