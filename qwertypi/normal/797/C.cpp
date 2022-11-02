#include <bits/stdc++.h>

using namespace std;

char mn[100001];
int main(){
	string s;
	cin >> s;
	int n = s.size();
	mn[n] = 'z' + 1;
	for(int i = n - 1; i >= 0; i--){
		mn[i] = min(mn[i + 1], s[i]);
	}
	string t = "", u = "";
	for(int i = 0; i < n; i++){
		while(!t.empty() && t.back() <= mn[i]) u.push_back(t.back()), t.pop_back();
		if(s[i] == mn[i]){
			u.push_back(s[i]);
		}else{
			t.push_back(s[i]);
		}
	}
	cout << u;
	reverse(t.begin(), t.end());
	cout << t << endl;
}