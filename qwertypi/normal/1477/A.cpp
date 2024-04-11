#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001];
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		int g = 0;
		for(int i = 1; i < n; i++){
			if(A[i] != A[0]) g = __gcd(g, A[i] - A[0]);
		}
		cout << ((k - A[0]) % g == 0 ? "YES" : "NO") << endl;
	}
}