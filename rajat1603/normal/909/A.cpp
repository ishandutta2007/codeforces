#include "bits/stdc++.h"
using namespace std;
string a , b;
string ans;
int main(){
	ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	cin >> a >> b;
	for(int i = 1 ; i <= a.size() ; ++i){
		for(int j = 1 ; j <= b.size() ; ++j){
			ans = min(ans , a.substr(0 , i) + b.substr(0 , j));
		}
	}
	cout << ans << endl;
}