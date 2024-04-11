#include <bits/stdc++.h>
using namespace std;

vector <char> v, w;
string s[2], t[2];

int main(){
	for(int i = 0; i < 2; i++) cin >> s[i];
	for(int i = 0; i < 2; i++) cin >> t[i];
	for(int i = 0; i < 2; i++) if(s[0][i] != 'X') v.push_back(s[0][i]);
	for(int i = 1; i >= 0; i--) if(s[1][i] != 'X') v.push_back(s[1][i]);
	for(int i = 0; i < 2; i++) if(t[0][i] != 'X') w.push_back(t[0][i]);
	for(int i = 1; i >= 0; i--) if(t[1][i] != 'X') w.push_back(t[1][i]);
	
	for(int i = 0; i < 3; i++){
		bool ok = 1;
		for(int j = 0; j < 3; j++) if(v[(j + i) % 3] != w[j]) ok = 0;
		if(ok){
			cout << "YES\n";
			return 0;
		}
	}
	
	cout << "NO\n";
	return 0;
}