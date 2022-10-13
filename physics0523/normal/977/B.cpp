#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	map<string,int> mp;
	int l;
	string s;
	cin >> l >> s;
	for(int i=1;i<l;i++){
		string tg;
		tg.push_back(s[i-1]);
		tg.push_back(s[i]);
		mp[tg]++;
	}
	vector<pair<int,string>> vp;
	for(auto &nx : mp){
		vp.push_back(make_pair(nx.second,nx.first));
	}
	sort(vp.begin(),vp.end());
	reverse(vp.begin(),vp.end());
	cout << vp[0].second << '\n';
  return 0;
}