#include <bits/stdc++.h>

using namespace std;

int A[100001][26];

void sub(){
	string s, t;
	cin >> s >> t;
	for(int i = 0; i < 26; i++){
		A[s.size()][i] = s.size();
	}
	for(int i = s.size() - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			if(s[i] == 'a' + j){
				A[i][j] = i;
			}else{
				A[i][j] = A[i + 1][j];
			}
		}
	}
	int curPos = 0;
	int ans = 1;
	for(auto i : t){
		if(curPos == s.size()){
			curPos = 0;
			ans++;
		}
		curPos = A[curPos][i - 'a'];
		if(curPos == s.size()){
			ans++;
			curPos = 0;
			curPos = A[curPos][i - 'a'];
			if(curPos == s.size()){
				cout << -1 << endl;
				return;
			}
		}
		curPos++;
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}