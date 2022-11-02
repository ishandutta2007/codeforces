#include <bits/stdc++.h>
using namespace std;
void sub(){
	string s;
	cin >> s;
	int l = 1 << 30, r = -1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1'){
			l = min(l, i);
			r = max(r, i);
		}
	}
	if(r == -1){
		cout << 0 << endl;
		return ;
	}
	int cnt = count(s.begin(), s.end(), '1');
	cout << r - l + 1 - cnt << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}