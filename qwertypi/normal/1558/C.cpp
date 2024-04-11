#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int A[2022];
vector<int> ans;
void qry(int x){
	reverse(A, A + x);
	ans.push_back(x);
}
void sub(){
	ans.clear();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		if((A[i] + i) % 2 == 0){
			cout << -1 << endl;
			return;
		}
	}
	for(int i = n; i > 1; i -= 2){
		int idx;
		idx = find(A, A + n, i) - A;
		qry(idx + 1);
		idx = find(A, A + n, i - 1) - A;
		qry(idx);
		idx = find(A, A + n, i - 1) - A;
		qry(idx + 2);
		qry(3);
		qry(i);
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i << ' '; 
	}
	cout << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}