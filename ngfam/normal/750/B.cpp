#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int test; cin >> test;

	int n = 0, w = 0, e= 0, s = 0;

	int cur = 0;

	while(test--){
		string a; int d;
		cin >> d >> a;



		if(a[0] == 'E' || a[0] == 'W'){
			if(cur == 0 || cur == 20000){
				puts("NO");
				return 0;
			}
	        	continue;
		}

	//	cout << cur << endl;

		if(a[0] == 'S'){
			

			cur += d;
			//cur %= 20000; 
			if(cur > 20000){
				puts("NO");
				return 0;
			}
		}
		else{
			cur -= d;
			if(cur < 0){
				puts("NO");
				return 0;
			}
		}
	}

	if(cur == 0) puts("YES");
	else puts("NO");
}