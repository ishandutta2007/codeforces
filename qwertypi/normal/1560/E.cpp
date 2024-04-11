#include <bits/stdc++.h>

using namespace std;

string vc;
bool vis[256];
int cnt[256];
int mul[256];

string erase(string& s, char c){
	string ret;
	for(auto i : s){
		if(i != c) ret.push_back(i);
	}
	return ret;
}

void solve(){
	vc = "";
	fill(vis + 'a', vis + 'z' + 1, 0);
	fill(cnt + 'a', cnt + 'z' + 1, 0);
	fill(mul + 'a', mul + 'z' + 1, 0);
	string t;
	cin >> t;
	int tar = t.size();
	reverse(t.begin(), t.end());
	for(auto i : t){
		if(!vis[i]) vis[i] = true, vc.push_back(i);
	}
	reverse(vc.begin(), vc.end());
	for(int i = 0; i < (int) vc.size(); i++){
		mul[vc[i]] = i + 1;
	}
	int ttl = 0;
	string ans;
	reverse(t.begin(), t.end());
	for(int i = 0; i < tar; i++){
		ttl += mul[t[i]];
		ans.push_back(t[i]);
		if(ttl >= tar) break;
	}
	string gen;
	string s = ans;
	for(int i = 0; i < (int) vc.size(); i++){
		gen += s;
		s = erase(s, vc[i]);
	}
	if(gen == t){
		cout << ans << ' ' << vc << endl;
	}else{
		cout << -1 << endl;
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}