#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[100000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	int prev = -1, cnt = 0;
	for(int i = 0; i < n; i++){
		if(A[i] == prev){
			cnt++;
			prev = A[i] + 1;
		}else if(A[i] > prev){
			cnt++;
			prev = A[i];
		}else{
			continue;
		}
	}
	cout << cnt << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}