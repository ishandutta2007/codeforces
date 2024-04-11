#include <bits/stdc++.h>
#define int long long
using namespace std;

int d[200000], t[200000];

map<int, pair<int, int>> A;
vector<pair<int, pair<int, int>>> B;
int sub(){
	A.clear();
	B.clear();
	int n, T, a, b;
	cin >> n >> T >> a >> b;
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	
	A[0] = {0, 0};
	A[T] = {0, 0};
	
	for(int i = 0; i < n; i++){
		if(d[i] == 0){
			A[t[i]].first++;
		}else{
			A[t[i]].second++;
		}
	}
	for(auto i : A){
		B.push_back(i); 
	}
	for(int i = 1; i < B.size(); i++){
		B[i].second.first += B[i - 1].second.first;
		B[i].second.second += B[i - 1].second.second;
	}
	int ans = 0;
	for(int i = 1; i < B.size(); i++){
		int res = B[i].first - (B[i - 1].second.first * a + B[i - 1].second.second * b) - 1;
		if(res < 0){
			continue;
		}
		int left_0 = B[B.size() - 1].second.first - B[i - 1].second.first;
		int left_1 = B[B.size() - 1].second.second - B[i - 1].second.second;
		int curAns = B[i - 1].second.first + B[i - 1].second.second;
		int g = min(left_0, res / a);
		curAns += g;
		res -= a * g;
		g = min(left_1, res / b);
		curAns += g;
		res -= b * g;
		ans = max(ans, curAns);
	}
	if(B[B.size() - 1].second.first * a + B[B.size() - 1].second.second * b <= T){
		ans = n;
	}
	cout << ans << endl;
	return 0;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}