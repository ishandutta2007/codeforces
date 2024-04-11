#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n;
	cin >> n;
	int sk = 0;
	int r,a;
	int mak = 0;
	for(int i = 0; i< n;i++){
		cin >> r >> a;
		sk -= r;
		sk += a;
		if(sk > mak){
			mak = sk;
		}
	}
	cout << mak;
	return 0;
}