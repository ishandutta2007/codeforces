#include <bits/stdc++.h>

using namespace std;

map<string, vector<int>> M;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s; int t;
		cin >> s >> t;
		M[s].push_back(t);
	}
	sort(M["00"].begin(), M["00"].end());
	sort(M["01"].begin(), M["01"].end());
	sort(M["10"].begin(), M["10"].end());
	int d0 = 0, d1 = 0;
	int ans = 0;
	for(auto i : M["11"]){
		d0++; d1++;
		ans += i;
	}
	M["11"].clear();
	int c0 = M["01"].size(), c1 = M["10"].size();
	int g = min(c0, c1);
	for(int i = 0; i < g; i++){
		int v1 = M["01"].back(), v2 = M["10"].back();
		ans += v1 + v2;
		M["01"].pop_back(); M["10"].pop_back();
	}
	vector<pair<int, string>> vi;
	for(auto i : M){
		for(auto j : i.second){
			vi.push_back({j, i.first});
		}
	}
	sort(vi.begin(), vi.end());
	for(int i = (int) vi.size() - 1; i >= 0; i--){
		if(d0 == 0 && vi[i].second[0] == '0' || d1 == 0 && vi[i].second[1] == '0') continue;
		ans += vi[i].first;
		d0 += (vi[i].second[0] == '1' ? 1 : -1);
		d1 += (vi[i].second[1] == '1' ? 1 : -1);
	}
	cout << ans << endl;
}