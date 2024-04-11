#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<set<int>> graph(300000);
vector<pair<int, int>> A;
int ans[300000];

ll f(ll x){
	return x * (x - 1) / 2;
}
int main(){
	fill(ans, ans+300000, 2);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		graph[v1].insert(v2);
		graph[v2].insert(v1);
		A.push_back({v1, v2});
	}
	ans[0] = 0;
	int First = n;
	for(int i = n - 1; i >= 1; i--){
		if(graph[0].find(i) == graph[0].end()){
			ans[i] = 0;
		}else{
			First = i;
		}
	}
	int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
	if(First != n){
		for(int i = n - 1; i >= 1; i--){
			if(graph[First].find(i) == graph[First].end() && ans[i] == 2){
				ans[i] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(ans[i] == 0){
			cnt_0++;
		}else if(ans[i] == 1){
			cnt_1++;
		}else{
			cnt_2++;
		}
	}
	ll total = f(n) - f(cnt_0) - f(cnt_1) - f(cnt_2);
	if(total != m || cnt_0 == 0 || cnt_1 == 0 || cnt_2 == 0){
		cout << -1;
		return 0;
	}
	for(auto i:A){
		if(ans[i.first] == ans[i.second]){
			cout << -1;
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] + 1 << ' ';
	}
}