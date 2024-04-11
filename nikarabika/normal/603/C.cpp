#include <bits/stdc++.h>

using namespace std;

int n, k, xya;

int gn(int x, int k){
	if(k){
		if(x == 0)
				return 0;
		if(x == 1)
				return 1;
		if(x == 2)
				return 0;
		if(x == 3)
				return 1;
		if(x == 4)
				return 2;
		if(x & 1)
				return 0;
		if(gn(x / 2, k) == 1)
				return 2;
		return 1;
	}
	if(x == 0)
			return 0;
	if(x == 1)
			return 1;
	if(x == 2)
			return 2;
	return 1 - (x & 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	k &= 1;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		x = gn(x, k);
		xya ^= x;
	}
	if(xya)
			cout << "Kevin\n";
	else
			cout << "Nicky\n";
	return 0;
}