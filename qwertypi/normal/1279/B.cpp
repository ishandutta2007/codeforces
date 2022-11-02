#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100000];
int prec[100000];
int best[100000];
void sub(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int sum = accumulate(A, A + n, 0LL);
	if(sum <= k){
		cout << 0 << endl;
		return;
	}
	best[0] = 0;
	for(int i = 1; i < n; i++){
		best[i] = best[i - 1];
		if(A[i] >= A[best[i]]){
			best[i] = i;
		}
	}
	prec[0] = A[0];
	for(int i = 1; i < n; i++){
		prec[i] = prec[i - 1] + A[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(prec[i] - A[best[i]] <= k){
			ans = best[i];
		}
	}
	cout << ans + 1 << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub(); 
	} 
}