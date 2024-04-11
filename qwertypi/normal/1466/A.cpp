#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[10000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	set<int> S;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			S.insert(abs(A[i] - A[j]));
		}
	}
	cout << S.size() << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}