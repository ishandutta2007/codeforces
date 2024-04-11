#include <iostream>
#include <stdio.h>

using namespace std;

string a,b;

int main() {
	int x,y;
	cin >> a >> b;
	x = y = 0;
	x = (10*(a[0]-'0') + (a[1]-'0')) * 60 + (10*(a[3]-'0') + a[4]-'0');
	y = (10*(b[0]-'0') + (b[1]-'0')) * 60 + (10*(b[3]-'0') + b[4]-'0');
	int k = x-y;
	if(k < 0) k += 24*60;
	printf("%02d:%02d\n",k/60,k%60);
	cin >> x;
	return 0;
}