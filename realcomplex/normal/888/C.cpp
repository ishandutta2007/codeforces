#include <bits/stdc++.h>

using namespace std;

const int AL = 26;
vector<int>v[AL];

void ini(){
	for(int j = 0;j<AL;j++){
		v[j].push_back(-1);
	}
}

int c(int l){
	int k = 0;
	for(int i = 1;i<v[l].size();i++){
		k = max(v[l][i]-v[l][i-1],k);
	}
	return k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ini();
	string s;
	cin >> s;
	for(int j = 0;j<s.size();j++)
		v[s[j]-97].push_back(j);
	int ans = INT_MAX;
	for(int i = 0;i<26;i++){
		v[i].push_back(s.size());
		ans = min(ans,c(i));
	}
	cout << ans << "\n";
	return 0;
}