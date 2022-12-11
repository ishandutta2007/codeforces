#include <iostream>
using namespace std;

int main() {
	
	long long n,m,a;
	cin >> n >> m >> a;
	long long sk = 0;
	long long r,s;
	r = n / a;
	if(n % a > 0){
		r++;
	}
	s = m / a;
	if(m % a > 0){
		s++;
	}
	cout <<s * r;
	return 0;
}