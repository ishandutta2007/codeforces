					/* in the name of Allah */
#include <iostream>
using namespace std;

int a, b;
int cnt;

int main(){
	cin >> a >> b;
	while(a >= b){
		cnt += b;
		a -= b - 1;
	}
	cout << cnt + a << endl;
	return 0;
}