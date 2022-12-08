#include <iostream>
#include <string>

using namespace std;

int rem(int x){
	int ret = 0, p = 1;
	while(x){
		if(x % 10){
			ret += (x % 10) * p;
			p *= 10;
		}
		x /= 10;
	}
	return ret;
}

int main(){
	int a, b;
	while(cin >> a >> b){
		cout << (rem(a) + rem(b) == rem(a+b) ? "YES" : "NO") << endl;
	}
	return 0;
}