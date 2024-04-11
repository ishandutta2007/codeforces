#include <bits/stdc++.h>

using namespace std;

void f(){
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int _min = (a + c - 1) / c + (b + d - 1) / d;
	if(_min <= e){
		cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << endl;
	}else{
		cout << -1 << endl; 
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		f();
	}
}