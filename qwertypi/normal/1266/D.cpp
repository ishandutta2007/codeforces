#include <bits/stdc++.h>
#define int long long
using namespace std;

int prec[100000];
int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v1, v2, p;
		cin >> v1 >> v2 >> p;
		prec[--v1] -= p;
		prec[--v2] += p;
	}
	vector<int> pos, neg;
	vector<pair<pair<int, int>, int>> ans;
	for(int i = 0; i < n; i++){
		if(prec[i] < 0){
			neg.push_back(i);
		}
		if(prec[i] > 0){
			pos.push_back(i);
		}
	}
	int i = 0, j = 0;
	while(i < neg.size()){
		int g1 = prec[neg[i]];
		int g2 = prec[pos[j]];
		int k = min(-g1, g2);
		prec[neg[i]] += k;
		prec[pos[j]] -= k;
		if(k != 0)
			ans.push_back({{neg[i], pos[j]}, k});
		if(prec[neg[i]] == 0){
			i++;
		}else{
			j++;
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i.first.first + 1 << ' ' << i.first.second + 1 << ' ' << i.second << endl;
	}
}