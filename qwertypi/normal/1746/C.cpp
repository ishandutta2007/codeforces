#include <bits/stdc++.h>

using namespace std;

int a[100001];
int s[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	set<pair<int, int>> S;
	for(int i = 1; i < n; i++){
		S.insert({a[i - 1] - a[i], i + 1});
	}
	vector<int> v;
	for(int i = n; i >= 1; i--){
		if(S.size()){
			pair<int, int> t = *--S.end();
			S.erase(--S.end());
			v.push_back(t.second);
		}else{
			v.push_back(1);
		}
	}
	reverse(v.begin(), v.end());
	for(auto i : v){
		cout << i << ' ';
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}