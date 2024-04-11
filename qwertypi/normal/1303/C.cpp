#include <bits/stdc++.h>
using namespace std;
#define int long long
char A[60];
void sub(){
	fill(A, A + 60, 0);
	string s;
	cin >> s;
	set<char> S;
	for(char i = 'a'; i <= 'z'; i++){
		S.insert(i);
	}
	int L = 26, R = 26;
	A[L] = s[0];
	int prev = L;
	for(auto i : s){
		S.erase(i);
	}
	set<char> T;
	T.insert(s[0]);
	for(int i = 1; i < s.size(); i++){
		if(A[prev + 1] == s[i]){
			prev++;
		}else if(A[prev - 1] == s[i]){
			prev--;
		}else{
			if(T.find(s[i]) != T.end()){
				cout << "NO" << endl;
				return;
			}
			if(!A[prev - 1]){
				prev--;
				A[prev] = s[i];
				L--;
			}else if(!A[prev + 1]){
				prev++;
				A[prev] = s[i];
				R++;
			}else{
				cout << "NO" << endl;
				return; 
			}
		}
		T.insert(s[i]);
	}
	for(auto i : S){
		R++;
		A[R] = i;
	}
	cout << "YES" << endl;
	for(int i = L; i <= R; i++){
		cout << A[i];
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