#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string t = s.substr(0, k);
	string s1;
	for(int i = 0; i < n; i++){
		s1.push_back(t[i % k]);
	}
	cout << n << endl;
	if(s1 >= s){
		cout << s1 << endl;
	}else{
		string s2 = t;
		int pos = k - 1;
		s2[pos]++;
		while(pos >= 0 && s2[pos] == '9' + 1){
			s2[pos] = '0';
			s2[pos - 1]++;
			pos--;
		}
		string ans;
		for(int i = 0; i < n; i++){
			ans.push_back(s2[i % k]);
		}
		cout << ans << endl;
	}
}