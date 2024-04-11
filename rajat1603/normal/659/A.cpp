#include "bits/stdc++.h"
using namespace std;
int n , a , b;
int main(){
	cin >> n >> a >> b;
	if(b > 0){
		while(b--){
			++a;
			if(a > n){
				a = 1;
			}
		}
	}
	else{
		b = abs(b);
		while(b--){
			--a;
			if(a == 0){
				a = n;
			}
		}
	}
	cout << a;
}