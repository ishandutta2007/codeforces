#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	int n;
	cin >> n;
	int A[256];
	while(n--){
		string s, t;
		cin >> s >> t;
		fill(A, A + 256, 0);
		for(auto i : s){
			A[i]++;
		}
		for(int j = 0; j < A['a']; j++){
			cout << 'a';
		}
		if(t[0] == 'a' && t[1] == 'b' && A['a'] > 0){
			for(int j = 0; j < A['c']; j++){
				cout << 'c';
			}
			for(int j = 0; j < A['b']; j++){
				cout << 'b';
			}
		}else{
			for(int j = 0; j < A['b']; j++){
				cout << 'b';
			}
			for(int j = 0; j < A['c']; j++){
				cout << 'c';
			}
		}
		
		for(int i = 'd'; i <= 'z'; i++){
			for(int j = 0; j < A[i]; j++){
				cout << (char) i;
			}
		}
		cout << endl;
	}
}