							/* in the name of Allah */
#include <iostream>
using namespace std;

int n, d[110];
int a, b;

int main(){
	while(cin >> n){
		for(int i = 0; i < n - 1; i++)
			cin >> d[i];
		cin >> a >> b;
		a--, b--;
		int sum = 0;
		for(int i = a; i < b; i++)
			sum += d[i];
		cout << sum << endl;
	}
	return 0;
}