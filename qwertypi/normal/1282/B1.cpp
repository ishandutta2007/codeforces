#include <bits/stdc++.h>

using namespace std;

int A[200000];
int cost[200001];
int sub(){
	int n, p, k;
	cin >> n >> p >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	} 
	sort(A, A + n);
	for(int i = 0; i < n; i++){
		if(i < k - 1){
			cost[i + 1] = cost[i] + A[i];
		}else{
			cost[i + 1] = cost[i - k + 1] + A[i];
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		if(cost[i] <= p){
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}