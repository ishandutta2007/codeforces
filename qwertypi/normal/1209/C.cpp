#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

using namespace std;

typedef long long ll;

char prec[200001];
int ans[200000];
string s;

bool valid(int n){
	vector<char> A;
	for(int i=0;i<n;i++){
		if(ans[i] == 1){
			A.emplace_back(s[i]);
		}
	}
	for(int i=0;i<n;i++){
		if(ans[i] == 2){
			A.emplace_back(s[i]);
		}
	}
	bool res = true;
	for(int i=0;i<n-1;i++){
		if(A[i] > A[i+1]){
			res = false;
		}
	}
	return res;
}


int solve(){
	int n;
	cin >> n;
	cin >> s;
	prec[n] = '9';
	for(int i=n-1;i>=0;i--){
		prec[i] = min(prec[i+1], s[i]);
	}
	char _min = '9';
	for(int i=0;i<n;i++){
		if(prec[i] == s[i] && s[i] <= _min){
			ans[i] = 1;
		}else{
			ans[i] = 2;
			_min = min(_min, s[i]);
		}
	}
	if(valid(n)){
		for(int i=0;i<n;i++){
			cout << ans[i];
		}
		cout << endl;
	}else{
		cout << '-' << endl;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}