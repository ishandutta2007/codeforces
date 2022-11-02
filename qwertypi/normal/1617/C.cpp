#include <bits/stdc++.h>

using namespace std;

int A[100001];
bool okay[100001];

int n;
void sub(){
	fill(okay, okay + n + 1, 0);
	sort(A, A + n);
	int l = 1;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(A[i] <= n && okay[A[i]] == 0){
			okay[A[i]] = 1;
		}else{
			while(okay[l]) l++;
			if(l <= (A[i] + 1) / 2 - 1){
				ans++;
				okay[l++] = true;
			}else{
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		sub();
	}
}