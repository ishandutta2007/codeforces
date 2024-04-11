#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	string s;
	cin >> s;
	char best = 'z' + 1;
	for(auto i:s){
		if(i > best){
			cout << "Ann" << endl;
		}else{
			best = i;
			cout << "Mike" << endl;
		}
	}
}