#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int q = 0, qa = 0, ans = 0;

	string s;
	cin >> s;
	for(auto c : s){
		if(c == 'Q'){
			ans += qa;
			++q;
		}
		else if(c == 'A'){
			qa += q;
		}
	}

	cout << ans;

	return 0;
}