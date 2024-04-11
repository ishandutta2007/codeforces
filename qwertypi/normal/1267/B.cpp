#include <bits/stdc++.h>

using namespace std;
int main(){
	string s;
	cin >> s;
	int L = 0, R = s.size() - 1;
	while(true){
		char c = s[L];
		int cnt = 0;
		if(s[R] != c){
			cout << 0;
			return 0;
		}
		while(L <= R && s[L] == c){
			L++;
			cnt++;
		}
		if(L > R){
			if(cnt + 1 < 3){
				cout << 0 << endl;
				return 0;
			}
			cout << cnt + 1 << endl;
			return 0;
		}
		while(L <= R && s[R] == c){
			R--;
			cnt++;
		}
		if(cnt < 3){
			cout << 0 << endl;
			return 0;
		}
	}
}