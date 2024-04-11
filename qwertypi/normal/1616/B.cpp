#include <bits/stdc++.h>

using namespace std;

int A[300001];
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t;
	if(n >= 2 && s[0] <= s[1]){
		cout << s[0] << s[0] << endl;
		return;
	}
	char c = 'z' + 1;
	for(auto i : s){
		if(i <= c){
			c = i;
			t.push_back(c);
		}else{
			break;
		}
	}
	cout << t;
	reverse(t.begin(), t.end());
	cout << t << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		solve();
	}
}