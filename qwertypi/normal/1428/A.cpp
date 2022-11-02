#include <bits/stdc++.h>

using namespace std;
#define int long long

void sub(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2 && y1 == y2){
		cout << 0 << endl;
	}else{
		int d1 = abs(x1 - x2), d2 = abs(y1 - y2);
		if(d1 > d2) swap(d1, d2);
		if(d1 == 0){
			cout << d2 << endl;
		}else{
			cout << (d1 + d2) + 2 << endl;
		}
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}