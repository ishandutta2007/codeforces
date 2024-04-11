#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define set unordered_set
#define map unordered_map
using namespace std;

vector<set<int>> ans;
map<int, int> ind;
map<int, set<int>> A;

void sub(){
	map<char, int> A;
	string s;
	cin >> s;
	A['L'] = 0;
	A['R'] = 0;
	A['U'] = 0;
	A['D'] = 0;
	for(auto i : s){
		A[i]++;
	}
	int min_L = min(A['L'], A['R']);
	int min_U = min(A['U'], A['D']);
	if(min_L == 0 || min_U == 0){
		if(min_L){
			cout << 2 << endl;
			cout << "LR" << endl;
		}
		if(min_U){
			cout << 2 << endl;
			cout << "UD" << endl;
		}
		if(min_L + min_U == 0){
			cout << 0 << endl;
		}
		return;
	}
	cout << 2 * (min_L + min_U) << endl;
	for(int i = 0; i < min_L; i++){
		cout << 'L';
	}
	for(int i = 0; i < min_U; i++){
		cout << 'U';
	}
	for(int i = 0; i < min_L; i++){
		cout << 'R';
	}
	for(int i = 0; i < min_U; i++){
		cout << 'D';
	}
	cout << endl;
}

int32_t main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
	return 0;
}