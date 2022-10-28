#include "bits/stdc++.h"
using namespace std;
int h , m , s;
int t1 , t2;
int a , b , c;
bool ok(int l , int r){
	if(a >= l && a <= r){
		return 0;
	}
	if(b >= l && b <= r){
		return 0;
	}
	if(c >= l && c <= r){
		return 0;
	}
	//cout << (1.0 * l / 120.0) << " " << (1.0 * r / 120.0) << endl;
	//cout << (1.0 * a / 120.0) << " " << (1.0 * b / 120.0) << " " << (1.0 * c / 120.0) << endl;
	return 1;
}
int main(){
	cin >> h >> m >> s;
	cin >> t1 >> t2;
	h %= 12;
	t1 %= 12;
	t2 %= 12;
	a = h * 30 * 120 + m * 60 + s;
	b = m * 6 * 120 + s * 12;
	c = s * 6 * 120;
	t1 *= 120 * 30;
	t2 *= 120 * 30;
	if(t1 < t2 && ok(t1 , t2)){
		printf("YES\n");
		return 0;
	}
	if(t1 < t2 && ok(0 , t1) && ok(t2 , 359 * 120)){
		printf("YES\n");
		return 0;
	}
	if(t2 < t1 && ok(t2 , t1)){
		printf("YES\n");
		return 0;
	}
	if(t2 < t1 && ok(0 , t2) && ok(t1 , 359 * 120)){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
}