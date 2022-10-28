#include "bits/stdc++.h"
using namespace std;
int n;
int main(){
	cin >> n;
	if(n <= 3){
		cout << "NO\n";
	}
	else if(n & 1){
		cout << "YES\n";
		int ctr = n - 1;
		for(int i = n ; i > 5 ; i -= 2){
			cout << i << " - " << i - 1 << " = " << "1\n";
			--ctr;
		}
		//5 * 4 + 3 + 2 - 1
		cout << "5 * 4 = 20\n";
		cout << "20 + 3 = 23\n";
		cout << "23 + 2 = 25\n";
		cout << "25 - 1 = 24\n";
		ctr -= 4;
		while(ctr){
			cout << "24 * 1 = 24\n";
			--ctr;
		}
	}
	else{
		cout << "YES\n";
		int ctr = n - 1;
		for(int i = n ; i > 4 ; i -= 2){
			cout << i << " - " << i - 1 << " = " << "1\n";
			--ctr;
		}
		cout << "1 * 2 = 2\n";
		cout << "2 * 3 = 6\n";
		cout << "6 * 4 = 24\n";
		ctr -= 3;
		while(ctr){
			cout << "24 * 1 = 24\n";
			--ctr;
		}
	}
}