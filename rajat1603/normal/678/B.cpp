#include "bits/stdc++.h"
using namespace std;
int n;
int delta = 0;
bool leap;
bool leapyear(int n){
	return ((n % 400) == 0) || ((n % 4) == 0) && (n % 100);
}
int main(){
	cin >> n;
	leap = leapyear(n);
	while(1){
		++n;
		if(((n % 400) == 0) || ((n % 4) == 0) && (n % 100)){
			delta += 2;
		}
		else{
			++delta;
		}
		if(delta % 7 == 0 && leapyear(n) == leap){
			break;
		}
	}
	cout << n;
}