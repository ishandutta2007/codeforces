#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<pair<int, pair<int, int>>> it;

int A[200010], B[200010];

int _count[200010], used[200010];

int parent[200010], size[200010];
void init(int n){
	for(int i = 0; i < n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int root(int x){
	if(x == parent[x]) return x;
	return parent[x] = root(parent[x]);
}

bool join(int x, int y){
	x = root(x), y = root(y);
	if(x == y) return false;
	parent[y] = x;
	size[x] += size[y];
	return true;
}


void sub(){
	int n, m;
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			int k;
			cin >> k;
			int cost = A[i] + B[k - 1];
			it.push_back({cost, {i, k - 1}});
		}
	}
	
	sort(it.begin(), it.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
		return a.first > b.first;
	});
	
	init(n);
	
	int64_t sum = 0;
	for(auto i : it){
		sum += i.first;
	}
	int64_t ans = 0;
	for(int i = 0; i < (int) it.size(); i++){
		int val = it[i].first, x = it[i].second.first, y = it[i].second.second;
		if(_count[x] == 0){
			ans += val;
			used[x] = y;
			_count[x]++;
		}else{
			if(join(used[x], y)){
				ans += val;
			}
		}
	}
	
	cout << sum - ans << endl;
}

int32_t main(){
	int t = 1;
	while(t--){
		sub();
	}
}