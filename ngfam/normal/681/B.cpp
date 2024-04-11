#include <bits/stdc++.h>

using namespace std;

const int house = 1234567, car = 123456, com = 1234;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int n; cin >> n;

	for(int a = 0; a <= n; a += house){
		for(int b = 0; b + a <= n; b += car){
			if((n - a - b) % com == 0){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}