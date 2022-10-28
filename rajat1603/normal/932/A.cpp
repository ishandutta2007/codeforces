#include "bits/stdc++.h"
using namespace std;
string str;
string ans;
int main(){
	cin >> str;
	ans = str;
	reverse(str.begin() , str.end());
	ans += str;
	cout << ans << endl;
}