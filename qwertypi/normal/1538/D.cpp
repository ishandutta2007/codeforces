#include <bits/stdc++.h>

using namespace std;

int pf(int x){
	int cnt = 0;
	for(int i = 2; i * i <= x; i++){
		while(x % i == 0) cnt++, x /= i;
	}
	cnt += x != 1;
	return cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, k;
		cin >> a >> b >> k;
		int r = pf(a) + pf(b);
		if(r < k){
			cout << "NO" << endl;
		}else{
			if((a % b == 0 || b % a == 0) && a != b || k >= 2){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
}