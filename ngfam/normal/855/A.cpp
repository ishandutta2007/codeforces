#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	set < string > x;

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i){
		string r;
		cin >> r;
		if(x.count(r)) cout << "YES\n";
		else cout << "NO\n";
		x.insert(r);
	}

	return 0;
}