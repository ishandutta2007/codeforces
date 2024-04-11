#include <bits/stdc++.h>

using namespace std;

int d(int x, int y){
	return abs(x - y);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n, p, l, r;

	cin >> n >> p >> l >> r;

	int x = (l != 1);
	int y = (r != n);


	if(p >= l && p <= r){
		if(x && y){
			cout << 2 + d(l, r) + min(d(p, l), d(p, r));
			return 0;
		}
		if(x) cout << 1 + d(p, l);
		else if(y) cout << 1 + d(r, p);
		else cout << 0;
		return 0;
	}

	if(p < l){
		if(!y) {
			cout << d(p, l) + 1;
		}
		else{
			cout << 1 + d(p, r) + x;
		}
	}
	else{
		if(!x){
			cout << d(p, r) + 1;
		}
		else{
			cout << 1 + d(p, l) + y;
		}
	}

	return 0;
}