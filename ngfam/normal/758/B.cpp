#include <bits/stdc++.h>

using namespace std;

int cnt[100];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	string f = "RYBG", s;

	cin >> s;

	int b = 0, r = 0, y = 0, g = 0;

	sort(f.begin(), f.end());

	do{
		bool ok = false;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '!') continue;
			if(s[i] != f[i % 4]){
				ok = true;
				break;
			}
		}
		if(ok == true){
			continue;
		}

		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '!'){
		        	++cnt[f[i % 4]];
			}
		}
		break;
	}while(next_permutation(f.begin(), f.end()));

	cout << cnt['R'] << " " << cnt['B'] << " " << cnt['Y'] << " " << cnt['G'];

	return 0;
}