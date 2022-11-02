#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a = 0, b = 0, c = 1;
		for(int a = 2; a <= 1000; a++){
			int g = a;
			g = __gcd(g, n - 1 - a);
			if(g == 1){
				cout << a << ' ' << n - 1 - a << ' ' << c << endl;
				break;
			}
		}
	}
}