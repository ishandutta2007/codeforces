#include <bits/stdc++.h>

using namespace std;
#define int long long

void sub(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	bool left = 1, right = 1;
	for(int i = 0; i < n; i++){
		if(s[i] == '<'){
			right = false;
		}
		
		if(s[i] == '>'){
			left = false;
		}
	}
	
	if(left || right){
		cout << n << endl;
	}else{
		int ans = 0;
		for(int i = 0; i < n; i++){
			bool res = (s[(i + n - 1) % n] == '-' || s[i] == '-');
			ans += res;
		}
		cout << ans << endl;
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}