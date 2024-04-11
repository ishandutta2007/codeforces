#include <bits/stdc++.h>

using namespace std;

void sub(){
	string a, b, c;
	cin >> a >> b >> c;
	int n = a.size();
	for(int i = 0; i < n; i++){
		if(a[i] != c[i] && b[i] != c[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}