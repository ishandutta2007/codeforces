#include <bits/stdc++.h>

using namespace std;

int sub(){
	int a, b, c, _r;
	cin >> a >> b >> c >> _r;
	if(a > b){
		swap(a, b);
	}
	int l = c - _r;
	int r = c + _r;
	int common = max(0, min(r, b) - max(l, a));
	cout << b - a - common << endl;
	return 0;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}