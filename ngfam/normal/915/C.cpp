#include <bits/stdc++.h>

using namespace std;

int cnt[22];

int check(string u){
	string x;
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < cnt[i]; ++j){
			x += char (i + '0');
		}
	}
	return !(u < x);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	string a, b;
	cin >> a >> b;

	if(a.size() < b.size()){
		sort(a.rbegin(), a.rend());
		cout << a;
		return 0;
	}

	for(int i = 0; i < a.size(); ++i){
		++cnt[a[i] - '0'];
	}

	string ans;
	bool ok = 0;

	for(int i = 0; i < a.size(); ++i){
		for(int x = b[i] - '0'; x >= 0; --x){
			if(cnt[x] == 0) continue;
			--cnt[x];


			if(x < b[i] - '0' || check(b.substr(i + 1, b.size() - i - 1))) {
				ans += char (x + '0');
				if(x < b[i] - '0'){
					ok = 1;
				}
				break;
			}
			else ++cnt[x];
		}
		if(ok) break;		
	}


	for(int i = 9; i >= 0; --i){
		for(int j = 0; j < cnt[i]; ++j){
			ans += char(i + '0');
		}
	}

	cout << ans;

	return 0;
}