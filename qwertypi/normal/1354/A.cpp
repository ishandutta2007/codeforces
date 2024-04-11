#include <bits/stdc++.h>
 
using namespace std;
#define int long long
void sub(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(b >= a){
		cout << b << endl;
		return;
	}
	if(c - d <= 0){
		cout << -1 << endl;
		return;
	}
	int t = (a - b + (c - d - 1)) / (c - d);
	cout << b + t * c << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}