#include <bits/stdc++.h>

using namespace std;

string f(int x){
	string s;
	for(int i = 0; i < x; i++) s.push_back('u');
	return s;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		if(n == 1){
			cout << 'u' << endl;
		}else if(n % 2 == 0){
			int k = (n - 1) / 2;
			cout << f(k) << 'w' << f(k + 1) << endl;
		}else{
			int k = (n - 3) / 2;
			cout << f(k) << "wv" << f(k + 1) << endl;
		}
	}
}