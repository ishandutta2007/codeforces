#include <bits/stdc++.h>
 
using namespace std;
 
int A[10];
 
void sub(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int pw3 = pow(3, n);
	for(int mask = 1; mask < pw3; mask++){
		int v = 0;
		int j = mask;
		for(int i = 0; i < n; i++){
			if(j % 3 == 2){
				v += A[i];
			}else if(j % 3 == 1){
				v -= A[i];
			}
			j /= 3;
		}
		if(v == 0){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--) sub();
}