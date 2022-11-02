#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> A;
vector<int> ans;

void test(){
	if(ans.size() != 0 && ans.size() != A.size()){
		cout << ans.size() << endl;
		for(auto i : ans){
			cout << i << ' ';
		} 
		cout << endl;
		exit(0);
	}
	ans.clear();
}

int mod(int a, int b){
	a %= (1 << b + 1);
	if(a < (1 << b + 1)){
		a += (1 << b + 1);
	}
	return (a >> b) % 2;
}

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		A.push_back({x, y});
	}
	for(int p = 0; p < 30; p++){
		for(int i = 0; i < n; i++){
			if(mod((A[i].first + A[i].second), p) == 0){
				ans.push_back(i + 1);
			}
		}
		test();
		for(int i = 0; i < n; i++){
			if(mod(A[i].first, p) == 0){
				ans.push_back(i + 1);
			}
		}
		test();
	}
}