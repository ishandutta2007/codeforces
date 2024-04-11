#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	int a, b; cin >> a >> b;

	if(a == 0 && b == 0){
		cout << "NO";
		return 0;
	}

	if(abs(a - b) > 1){
		cout << "NO";
	}
	else{
		cout << "YES";
	}

	return 0;
}