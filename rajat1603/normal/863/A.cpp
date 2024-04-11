#include "bits/stdc++.h"
using namespace std;
string t;
bool check(string t){
	int l = 0;
	int r = t.size() - 1;
	while(l <= r){
		if(t[l] != t[r]){
			return 0;
		}
		++l;
		--r;
	}
	return 1;
}
int main(){
	cin >> t;
	for(int i = 0 ; i < 10 ; ++i){
		if(check(t)){
			cout << "YES\n";
			return 0;
		}
		t = "0" + t;
	}
	cout << "NO\n";
}