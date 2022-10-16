#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int n;

bool isprime(int n){
	if(n < 2) return 0;
	if(n == 2) return 1;
	for(int j = 2;j<=sqrt(n);j++){
		if(n%j == 0) return 0;
	}
	return 1;

}

int main(){

	cin >> n;
	if(isprime(n)){
		cout << 1 << endl;
		return 0;
	}
	if(isprime(n-2)){
		cout << 2 << endl;
		return 0;
	}
	if(n%2 == 0){
		cout << 2 << endl;
		return 0;
	}
	if(n%2 == 1){
		cout << 3 << endl;
		return 0;
	}


}