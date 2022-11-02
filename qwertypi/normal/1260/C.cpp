#include <bits/stdc++.h>

using namespace std;

void sub(){
	int r, b, k;
	cin >> r >> b >> k;
	if(r > b){
		swap(r, b);
	}
	int g = __gcd(r, b);
	r /= g;
	b /= g;
	
	if((b - 2) / r + 1 >= k){
		cout << "REBEL" << endl;
	}else{
		cout << "OBEY" << endl;
	}
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}