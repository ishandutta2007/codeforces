#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	int n; cin >> n;

	string s;
	cin >> s;

	int ans = 0;

	for(int i = 0; i < s.size(); ++i){
		set < char > x;

		int cnt = 0;

		for(int j = i; j < s.size(); ++j){
			if(isupper(s[j])) break;
			cnt += 1 - x.count(s[j]);
			x.insert(s[j]);
		}

		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}