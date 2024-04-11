#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
int n , k;
int a , b , c , d;
void path(){
	set < int > s;
	s.clear();
	for(int i = 1 ; i <= n ; ++i){
		s.insert(i);
	}
	s.erase(a);
	s.erase(b);
	s.erase(c);
	s.erase(d);
	for(int x : s){
		cout << x << " ";
	}
}
int main(){
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	if(n == 4){
		cout << "-1\n";
		return 0;
	}
	if(n == 5 && k < 6){
		cout << "-1\n";
		return 0;
	}
	if(k < n + 1){
		cout << "-1\n";
		return 0;
	}
	if(n == 5){
		int e = 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ a ^ b ^ c ^ d;
		cout << a << " " << c << " " << e << " " << d << " " << b << endl;
		cout << c << " " << a << " " << e << " " << b << " " << d << endl;
		return 0;
	}
	cout << a << " " << d << " ";
	path();
	cout << c << " " << b << endl;
	cout << c << " " << b << " ";
	path();
	cout << a << " " << d << endl;
}