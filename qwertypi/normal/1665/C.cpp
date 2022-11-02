// 
// 

#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)

using namespace std;

const int mod = 1e9 + 7;

int p[300001];
vector<vector<int>> G(300001);

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		G[i].clear();
	}
	for(int i = 1; i < n; i++){
		cin >> p[i];
		p[i]--;
		G[p[i]].push_back(i);
	}
	vector<int> M;
	for(int i = 0; i < n; i++){
		if(G[i].size() != 0) M.push_back(G[i].size());
	}
	M.push_back(1);
	sort(M.begin(), M.end());
	int T = 0;
	int rm_spread = 0;
	for(int i = (int) M.size() - 1; i >= 0; i--){
		T++;
		for(int j = i; j < M.size(); j++){
			M[j]--;
		}
		while(!M.empty() && M.back() <= 0) M.pop_back();
	}
	multiset<int> a1, a2;
	for(auto i : M) if(i > 0) a1.insert(i);
	while(!a1.empty()){
		T++;
		int mx = 0;
		for(auto i : a1){
			mx = max(i, mx);
			if(i > 1) a2.insert(i - 1);
		}
		if(a2.find(mx - 1) != a2.end())a2.erase(a2.find(mx - 1));
		if(mx > 2) a2.insert(mx - 2);
		swap(a1, a2);
		a2.clear();
	}
	cout << T << endl;
}

int32_t main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
}