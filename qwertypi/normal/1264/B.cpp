#include <bits/stdc++.h>

using namespace std;
int A[400000];
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int odd = a + c;
	int even = b + d;
	if(a == b + 1 && c == 0 && d == 0){
		cout << "YES" << endl;
		for(int i = 0; i < b; i++){
			cout << 0 << ' ' << 1 << ' ';
		}
		cout << 0;
		return 0;
	}

	if(d == c + 1 && a == 0 && b == 0){
		cout << "YES" << endl;
		for(int i = 0; i < c; i++){
			cout << 3 << ' ' << 2 << ' ';
		}
		cout << 3;
		return 0;
	}
	
	if(abs(odd - even) > 1 || a > b || d > c){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if(odd >= even){
		for(int i = 0; i < min(a, b); i++){
			cout << 0 << ' ' << 1 << ' ';
		}
		int g = min(a, b);
		a -= g, b -= g;
		for(int i = 0; i < min(b, c); i++){
			cout << 2 << ' ' << 1 << ' ';
		}
		g = min(b, c);
		b -= g, c -= g;
		for(int i = 0; i < min(c, d); i++){
			cout << 2 << ' ' << 3 << ' ';
		}
		g = min(c, d);
		c -= g, d -= g;
		if(c){
			cout << 2 << endl;
		}
	}else{
		for(int i = 0; i < min(c, d); i++){
			cout << 3 << ' ' << 2 << ' ';
		}
		int g = min(c, d);
		c -= g, d -= g;
		for(int i = 0; i < min(b, c); i++){
			cout << 1 << ' ' << 2 << ' ';
		}
		g = min(b, c);
		b -= g, c -= g;
		for(int i = 0; i < min(a, b); i++){
			cout << 1 << ' ' << 0 << ' ';
		}
		g = min(a, b);
		a -= g, b -= g;
		if(b){
			cout << 1 << endl;
		}
	}
}