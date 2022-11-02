#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	string s;
	cin >> s;
	vector<char> o, e;
	for(auto i : s){
		if(i % 2) o.push_back(i);
		else e.push_back(i);
	}
	set<char> so, se;
	for(auto i : o){
		so.insert(i);
	}
	
	for(auto i : e){
		se.insert(i);
	}
	
	for(auto i : so){
		for(auto j : se){
			if(abs(i - j) != 1){
				string ans1, ans2;
				bool b1 = false, b2 = false;
				for(auto i2 : o){
					if(i2 == i && !b1){
						b1 = true;
						continue;
					}
					ans1.push_back(i2);
				}
				for(auto j2 : e){
					if(j2 == j && !b2){
						b2 = true;
						continue;
					}
					ans2.push_back(j2);
				}
				reverse(ans2.begin(), ans2.end());
				cout << ans1 << i << j << ans2 << endl;
				return;
			}
		}
	}
	if(so.size() == 0 || se.size() == 0){
		cout << s << endl;
	}else{
		cout << "No answer" << endl;
	}
}

int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}