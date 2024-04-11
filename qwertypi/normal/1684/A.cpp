#include <bits/stdc++.h>

// nothing to say
using namespace std;

void solve(){
	int n; cin >> n;
	if(n >= 10 && n <= 99){
		cout << n % 10 << endl;
	}else{
		vector<int> s;
		while(n){
			s.push_back(n % 10); n /= 10;
		}
		sort(s.begin(), s.end());
		cout << s[0] << endl;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}