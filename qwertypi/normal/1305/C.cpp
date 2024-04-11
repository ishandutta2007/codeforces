#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001];
int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	if(n > m){
		cout << 0 << endl;
	}else{
		int ans = 1;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				ans = (ans * abs(A[i] - A[j])) % m;
			}
		}
		cout << ans << endl;
	}
}