#include <bits/stdc++.h>

using namespace std;
#define int long long

void sub(){
	string s;
	cin >> s;
	int cnt = 0;
	for(auto i : s){
		if(i == 'B' && cnt > 0){
			cnt--;
		}else{
			cnt++;
		}
	}
	cout << cnt << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}