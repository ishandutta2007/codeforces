#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n, k, t;

	cin >> n >> k >> t;

	if(t <= k){
		cout << t;
	}
	else{
		if(t > n){
			cout << k - (t - n);
		}
		else{
			cout << k;
		}
	}

	return 0;
}