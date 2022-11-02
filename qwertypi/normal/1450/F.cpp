#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[300000], cnt[300001];

vector<pair<int, int>> B;
void sub(){
	B.clear();
	int n;
	cin >> n;
	fill(cnt, cnt + n + 1, 0);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	A[n] = A[n - 1];
	int st = 0, _max = 0, best = -1;
	for(int i = 0; i <= n - 1; i++){
		if(A[i] == A[i + 1]){
			if(A[st] == A[i]){
				cnt[A[st]]++;
				if(cnt[A[st]] > _max){
					_max = cnt[A[st]];
					best = A[st];
				}
			}
			
			B.push_back({st, i});
			st = i + 1;
		}
	}
	
	if(B.size() == 1){
		cout << 0 << endl;
		return;
	}
	
//	for(auto i : B){
//		cout << i.first << ' ' << i.second << endl;
//	}
	for(auto i : B){
		if(A[i.first] != best && A[i.second] != best){
			_max--;
		}
	}
	
	int cnt = 0;
	for(auto i : B){
		for(int j = i.first; j < i.second; j++){
			if(A[j] != best && A[j + 1] != best){
				cnt++;
			}
		} 
	}
	
	if(cnt < _max - 1){
		cout << -1 << endl;
	}else{
		cout << B.size() - 1 + max(_max - 1, 0LL) << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}