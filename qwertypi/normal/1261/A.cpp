#include <bits/stdc++.h>

using namespace std;

int prec[2001];

bool exp(int s, int k, int x){
	if(x < 2 * (k - 1)){
		return x % 2 == 0;
	}else{
		return x < (s - 2 * (k - 1)) / 2 + 2 * (k - 1);
	}
}

char to_char(bool x){
	if(x){
		return '(';
	}else{
		return ')';
	}
}

void sub(){
	vector<pair<int, int>> ans;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int len = s.size(); 
	prec[0] = 0;
	for(int i = 0; i < len; i++){
		char c = to_char(exp(len, k, i));
		for(int j = i; j < len; j++){
			if(s[j] == c){
				ans.push_back({i, j});
				reverse(s.begin() + i, s.begin() + j + 1);
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i.first + 1 << ' ' << i.second + 1 << endl;
	}
}
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		sub();
	}
}