#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int par;
	int sk = 0;
	int k1 = 0,k2 = 0,k3 = 0;
	for(int i = 0;i<n;i++){
		cin >> par;
		if(par == 4){
			sk++;
		}
		else if(par == 3){
			k3++;
		}
		else if(par == 2){
			k2++;
		}
		else{
			k1++;
		}
	}
	sk += k2 / 2;
	k2 %= 2;
	if(k1 > k3){
		sk += k3;
		k1 -= k3;
		k3 = 0;
	}
	else{
		sk += k1;
		k3 -= k1;
		sk += k3;
		k1 = 0;
	}
	k2 *= 2;
	k2 += k1;
	sk += k2 / 4;
	if(k2 % 4 != 0){
		sk++;
	}
	cout << sk;
	return 0;
}