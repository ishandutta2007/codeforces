#include <bits/stdc++.h>

using namespace std;

vector<int> A; 
map<int, vector<int>> B;
set<int> C;
vector<vector<int>> D;
set<int> E;
void sub(){
	A.clear();
	B.clear();
	C.clear();
	D.clear();
	E.clear();
	int n;
	cin >> n;
	A.resize(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
		B[A[i]].emplace_back(i); 
	}
	int cnt = 0;
	for(auto i : B){
		for(auto j : i.second){
			A[j] = cnt;
		}
		cnt++;
	}
	D.resize(cnt);
	for(int i = 0; i < n; i++){
		if(C.upper_bound(A[i]) != C.end()){
			int larger = *(C.upper_bound(A[i]));
			D[larger].emplace_back(A[i]);
		}
		C.insert(A[i]);
	}
	int ans = n;
	for(int i = 0; i < cnt; i++){
		int res = cnt - i - 1;
		for(auto j : D[i]){
			E.insert(j);
		}
		int _max = (E.size() == 0 ? -1 : *(--E.end()));
		ans = min(ans, res + _max + 1);
	}
	cout << ans << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}