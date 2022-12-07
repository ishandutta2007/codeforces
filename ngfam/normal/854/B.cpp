#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n, k;

	cin >> n >> k;

	if(k == n || k == 0){
		cout << 0 << " " << 0 << endl;
		return 0;
	}

	int lmin = 1;
	int lmax = min(n - k, k * 2);

	cout << lmin << " " << lmax << endl;

	return 0;
}