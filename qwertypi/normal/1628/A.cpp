#include <bits/stdc++.h>

using namespace std;

int A[200013];
int ha[200013];
int mex[200013];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i <= n; i++) ha[i] = 0;
	int curMex = 0;
	for(int i = n - 1; i >= 0; i--){
		ha[A[i]]++;
		while(ha[curMex]) curMex++;
		mex[i] = curMex;
	}
	curMex = 0;
	int prev = 0;
	vector<int> ans;
	for(int i = 0; i <= n; i++) ha[i] = 0;
	vector<int> painted;
	for(int i = 0; i < n; i++){
		ha[A[i]]++;
		painted.push_back(A[i]);
		while(ha[curMex]) curMex++;
		if(curMex == mex[prev]){
			ans.push_back(curMex);
			prev = i + 1;
			for(auto i : painted){
				ha[i] = false;
			}
			painted.clear();
			curMex = 0;
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans) cout << i << ' ';
	cout << endl; 
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}