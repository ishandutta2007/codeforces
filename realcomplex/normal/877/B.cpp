#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int main(){
	string s;
	cin >> s;
	int ac = 0;
	int bc = 0;
	int as = 0;
	int ans = 0;
	int t = 0;
	for(char x : s)t+=(x=='a');
	ans = t;
	for(int j = 0;j<s.size();j++){
		if(s[j] == 'a')ac++;
		as = 0;
		bc = 0;
		for(int i = j;i<s.size();i++){
			if(s[i]=='b')bc++;
			else as++;
			ans = max(ans,ac+bc+(t-(as+ac)));
		}
	}
	cout << ans;
	return 0;
}