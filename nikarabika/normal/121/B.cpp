#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

int n, k;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> s;
	s = s + "000";
	for(int i = 0; i < n; i += 2){
		if(i + 2 < n and s[i] == '4' and (s[i + 1] == '4' or s[i + 1] == '7') and s[i + 2] == '7'){
			if(k & 1){
				if(s[i + 1] == '4')
					s[i + 1] = '7';
				else
					s[i + 1] = '4';
			}
			cout << s.substr(0, sz(s) - 3) << endl;
			return 0;
		}
		if(s[i] == '4' and s[i + 1] == '7' and k)
			s[i + 1] = '4', k--;
		if(s[i + 1] == '4' and s[i + 2] == '7' and k)
			s[i + 1] = '7', k--;
		if(!k){
			cout << s.substr(0, sz(s) - 3) << endl;
			return 0;
		}
	}
	cout << s.substr(0, sz(s) - 3) << endl;
	return 0;
}