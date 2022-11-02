#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int parents[200001];

int Root(int x){
	while(parents[x] != x){
		parents[x] = parents[parents[x]];
		x = parents[x];
	}
	return x;
}

void Union(int x, int y){
	int root_x = Root(x);
	int root_y = Root(y);
	parents[root_x] = root_y;
}

void sub(){
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++){
		parents[i] = i;
	}
	vector<pair<int, int>> voters;
	for(int i = 0; i < n; i++){
		int v1, v2;
		cin >> v1 >> v2;
		voters.push_back({v2, v1});
	}
	sort(voters.begin(), voters.end(), [](pair<int, int> A, pair<int, int> B){
		return A.first > B.first || (A.first == B.first && A.second < B.second);
	});
	ll ans = 0;
	for(auto i : voters){
		int root = Root(i.second);
		if(root != n)
			Union(root, root + 1);
		else
			ans += i.first;
	}
	cout << ans << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
	return 0;
}