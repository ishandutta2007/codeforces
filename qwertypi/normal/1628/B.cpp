#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	bool DONE = false;
	vector<string> vs;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(s.size() == 1){
			DONE = true;
		}else if(s.size() == 2 && s[0] == s[1] || s.size() == 3 && s[0] == s[2]){
			DONE = true;
		}
		vs.push_back(s);
	}
	if(DONE){
		cout << "YES" << endl;
		return;
	}
	set<string> S2, S2p, S3;
	for(int i = 0; i < n; i++){
		string s = vs[i];
		if(s.size() == 2){
			string t;
			t.push_back(s[1]); t.push_back(s[0]);
			if(S2.find(t) != S2.end() || S2p.find(t) != S2p.end()){
				cout << "YES" << endl;
				return;
			}
		}else{
			string t;
			t.push_back(s[2]); t.push_back(s[1]);
			if(S2.find(t) != S2.end()){
				cout << "YES" << endl;
				return;
			}
			t.push_back(s[0]);
			if(S3.find(t) != S3.end()){
				cout << "YES" << endl;
				return;
			}
		}
		if(s.size() == 2){
			S2.insert(s);
		}else{
			S2p.insert(s.substr(0, 2));
			S3.insert(s);
		}
	}
	cout << "NO" << endl; 
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}