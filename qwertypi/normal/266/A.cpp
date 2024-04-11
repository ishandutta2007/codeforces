#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	char prev = ' ';
	for(int i=0;i<(int)s.size();i++){
		if(prev == s[i]){
			ans++;
		}else{
			prev = s[i];
		}
	}
	cout << ans;
}