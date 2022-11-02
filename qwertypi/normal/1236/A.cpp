#include <bits/stdc++.h>

using namespace std;

void sub(){
	int a, b, c;
	cin >> a >> b >> c;
	int _min = min(b, c / 2);
	b -= _min;
	int ans = _min;
	_min = min(a, b / 2);
	ans += _min;
	cout << ans * 3 << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}