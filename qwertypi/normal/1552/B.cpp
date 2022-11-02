#include <bits/stdc++.h>

using namespace std;

int A[50000][5];

int cmp(int a, int b){
	int cnt = 0;
	for(int j = 0; j < 5; j++){
		cnt += A[a][j] <= A[b][j];
	}
	return cnt >= 3;
}

void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			cin >> A[i][j];
		}
	}
	int idx = 0;
	for(int i = 1; i < n; i++){
		if(!cmp(idx, i)){
			idx = i;
		}
	}
	for(int i = 0; i < n; i++){
		if(!cmp(idx, i)){
			cout << -1 << endl;
			return;
		}
	}
	cout << idx + 1 << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--) sub();
}