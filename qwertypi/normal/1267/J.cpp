#include <bits/stdc++.h>

using namespace std;

void sub(){
	map<int, int> cnt;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		cnt[v]++;
	}
	map<int, int> res;
	for(auto i : cnt){
		res[i.second]++;
	}
	int _min = res.begin() -> first;
	int count = res.size();
	for(int i = _min + 1; i >= 1; i--){
		int cnt = 0;
		bool OK = true;
		for(auto v : res){
			if(!((i - 1) * ((v.first + i - 1) / i) <= v.first)){
				OK = false;
				break;
			}
			cnt += (v.first + i - 1) / i * v.second;
		}
		if(OK){
			cout << cnt << endl;
			return;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}