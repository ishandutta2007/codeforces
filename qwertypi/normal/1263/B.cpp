#include <bits/stdc++.h>
using namespace std;

vector<string> A;
map<string, int> S;

string change(string s){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 10; j++){
			string s1 = s.substr(0, i);
			s1.push_back('0' + j);
			s1 += s.substr(i + 1, 3 - i);
			if(S.find(s1) == S.end()){
				return s1;
			}
		}
	}
}

void sub(){
	A.clear();
	S.clear();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		A.push_back(s);
		S[s]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(S[A[i]] > 1){
			S[A[i]]--;
			A[i] = change(A[i]);
			S[A[i]]++; 
			ans++;
		}
	}
	cout << ans << endl;
	for(auto i : A){
		cout << i << endl;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}