#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200000];
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	int ans = -1;
	int cur = 0;
	int need = 0;
	for(int i = 0; i < n; i++){
		if(cur >= need){
			ans++;
			cur = 0;
			need = A[i];
		}
		cur++;
		need = max(need, A[i]);
	}
	if(cur >= need){
		ans++;
	}
	cout << ans << endl;
}

int pow_10[19];
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}