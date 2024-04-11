#include <bits/stdc++.h>

using namespace std;

int n, x;
set < int > s;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n >> x;

	int ans = 0;

	for(int i = 1; i <= n; ++i){
		int t;
		cin >> t;
		if(t == x){
			++ans;
		}
		else{
			s.insert(t);
		}
	}

	for(int i = 0; i < x; ++i){
		if(s.count(i) == 0){
			++ans;
		}
	}

	cout << ans;

	return 0;
}