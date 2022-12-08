							/* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int a, b, n;

int main(){
	cin >> a >> b >> n;
	bool can = false;
	for(int i = -1000; i <= 1000; i++){
		int t = a;
		for(int j = 0; j < n; j++){
			t *= i;
			if(abs(t) > abs(b))
				break;
		}
		if(t == b){
			cout << i << endl;
			can = true;
			break;
		}
	}
	if(!can)
		cout << "No solution" << endl;
	return 0;
}