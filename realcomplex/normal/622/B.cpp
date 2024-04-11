#include <iostream>
using namespace std;
 
int main() {
	int a,b;
	char s;
	cin >> a >> s >> b;
	int laiks = (a*60)+b;
	int add;
	cin >> add;
	laiks += add;
	laiks %= 1440;
	int h,m;
	h = laiks/60;
	m = laiks%60;
	if(h < 10){
		cout << 0;
	}
	cout << h << ":";
	if(m < 10){
		cout << 0;
	}
	cout << m;
	return 0;
}