#include <bits/stdc++.h>

using namespace std;

void f(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int _max = -1;
	int _min = n;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			_max = i;
			cnt++;
		}
	}
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '1'){
			_min = i;
		}
	}
	int ans = max(max(n + cnt, 2 * (_max + 1)), 2 * (n - _min));
	cout << ans << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		f();
	}
}