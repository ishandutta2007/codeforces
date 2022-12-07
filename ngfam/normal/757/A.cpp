#include <bits/stdc++.h>

using namespace std;

int f(char c){
	if(c > 'Z') return c - 'a' + 26;
	return c - 'A';
}

int cnt[100];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	string s; cin >> s;

	for(int i = 0; i < s.size(); ++i){
//		cout << s[i] << " " << f(s[i]) << endl;

		++cnt[f(s[i])];		
	}

	string t = "Bubasrl";
	
	int ans = s.size();

	for(int i = 0; i < t.size(); ++i){
		int u = f(t[i]);

		//cout << t[i] << " " << u << " " << cnt[u] << endl;

		if(t[i] == 'a' || t[i] == 'u'){
			ans = min(ans, cnt[u] / 2);
		}
		else{
			ans = min(ans, cnt[u]);
		}
	}

	cout << ans;

	return 0;
}