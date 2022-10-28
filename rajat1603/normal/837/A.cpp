#include "bits/stdc++.h"
using namespace std;
int n;
string str;
int ans;
int cur;
int main(){
	cin >> n;
	while(cin >> str){
		cur = 0;
		for(char c : str){
			cur += (c >= 'A') && (c <= 'Z');
		}
		ans = max(ans , cur);
	}
	cout << ans << endl;
}