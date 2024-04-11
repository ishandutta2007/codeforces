#include <bits/stdc++.h>

using namespace std;

char o(char a = ' ', char b = ' '){
	if(a != 'a' && b != 'a') return 'a';
	if(a != 'b' && b != 'b') return 'b';
	if(a != 'c' && b != 'c') return 'c';
}
int main(){
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	string ans(n, '_');
	for(int i = 0; i < n; i++){
		ans[i] = o(s[i], t[i]);
	}
	int T = n;
	for(int i = 0; i < n; i++){
		if(T > k && s[i] == t[i]) ans[i] = s[i], T--;
	}
	int t0 = T, t1 = T;
	for(int i = 0; i < n; i++){
		if(s[i] == t[i]) continue;
		if(t0 > k){
			ans[i] = s[i], t0--;
			continue;
		}

		if(t1 > k){
			ans[i] = t[i], t1--;
			continue;
		}
	}
	if(t0 != k || t1 != k){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
}