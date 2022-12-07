#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int ans = 0;

	string s;

	cin >> s;

	for(auto c : s){
		if(isdigit(c)){
			if(c % 2) ++ans;
		}
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++ans;
	}

	cout << ans;

	return 0;
}