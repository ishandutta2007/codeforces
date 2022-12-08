						/* in the name of Allah */
#include <iostream>
using namespace std;

int n;

int main(){
	cin >> n;
	cout << (n / 2) * ((n + 1) / 2) << endl;
	for(int i = 1; i <= n; i += 2)
		for(int j = 2; j <= n; j += 2)
			cout << i << ' ' << j << endl;
	return 0;
}