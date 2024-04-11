#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[300000];
int min_B[3000];
void sub(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a == 1){
		cout << ((n >= 1 && (n - 1) % b == 0) ? "Yes" : "No") << endl;
		return;
	}else{
		int v = 1;
		while(v <= n){
			if(n >= v && (n - v) % b == 0){
				cout << "Yes" << endl;
				return;
			}
			v *= a;
		}
	}
	cout << "No" << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--) sub();
}