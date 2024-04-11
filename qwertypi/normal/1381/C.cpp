#include <bits/stdc++.h>
 
using namespace std;

int A[100010], ans[100010];

vector<vector<int>> G(100010);

set<pair<int, int>> S;
set<int> Free;

pair<int, int> upd(int no = -1){
	pair<int, int> op = *S.begin();
	S.erase(op);
	int pos = G[op.second].back();
	G[op.second].pop_back();
	if(op.first != -1){
		S.insert({op.first + 1, op.second});
	}

	return {pos, op.second};
}

int cnt = 0;

bool get2(bool sp = false){
	if(S.size() < 2) return false;
	pair<int, int> op1 = *S.begin();
	S.erase(op1);
	int pos1 = G[op1.second].back();
	G[op1.second].pop_back();
	
	pair<int, int> op2 = *S.begin();
	S.erase(op2);
	int pos2 = G[op2.second].back();
	G[op2.second].pop_back();
	
	// cout << pos1 << ' ' << pos2 << endl;
	ans[pos1] = op2.second;
	if(!sp) ans[pos2] = op1.second;
	
	if(op1.first != -1){
		S.insert({op1.first + 1, op1.second});
	}
	if(op2.first != -1){
		S.insert({op2.first + 1, op2.second});
	}
	
	return true;
}

bool get3(void){
	if(S.size() < 3) return false;
	pair<int, int> op1 = *S.begin();
	S.erase(op1);
	int pos1 = G[op1.second].back();
	G[op1.second].pop_back();
	
	pair<int, int> op2 = *S.begin();
	S.erase(op2);
	int pos2 = G[op2.second].back();
	G[op2.second].pop_back();

	pair<int, int> op3 = *S.begin();
	S.erase(op3);
	int pos3 = G[op3.second].back();
	G[op3.second].pop_back();
	
	ans[pos1] = op2.second;
	ans[pos2] = op3.second;
	ans[pos3] = op1.second;
	
	if(op1.first != -1){
		S.insert({op1.first + 1, op1.second});
	}
	if(op2.first != -1){
		S.insert({op2.first + 1, op2.second});
	}
	if(op3.first != -1){
		S.insert({op3.first + 1, op3.second});
	}
	
	return true;
}

int n, x, y;

void go(){
	bool OK = true;
	while(cnt >= 5){
		OK &= get2();
		cnt -= 2;
	}
	if(cnt == 4){
		OK &= get2();
		cnt -= 2;
	}
	if(!OK){
		cout << "NO" << endl;
		return;
	}
	if(cnt == 3){
		if(!get3()){
			OK &= get2();
			cnt -= 2;
		}else{
			cnt = 0;
		}
	}
	if(cnt == 2){
		OK &= get2();
	}
	if(cnt == 1){
		OK &= get2(true);
	}

	if(!OK){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}

void sub(){
	cin >> n >> x >> y;
	
	Free.clear();
	S.clear();
	for(int i = 1; i <= n + 1; i++){
		G[i].clear();
		Free.insert(i);
	}
	
	for(int i = 0; i < n; i++){
		cin >> A[i];
		G[A[i]].push_back(i);
	}
	
	
	for(int i = 1; i <= n + 1; i++){
		if(G[i].size()){
			Free.erase(i);
			S.insert({-G[i].size(), i});
		}
	}
	int iron = *Free.begin();
	
	fill(ans, ans + n, iron); // rich
	
	for(int i = 0; i < x; i++){
		pair<int, int> v = upd();
		ans[v.first] = v.second;
	}
	
	cnt = y - x;
	go();
	
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}