								/* in the name of Allah */
#include <iostream>
using namespace std;

int x1, x2, a, b;

int main(){
	while(cin >> x1 >> x2 >> a >> b){
		bool ch = false;
		if(x1 > x2){
			swap(x1, x2);
			swap(a, b);
			a = -a;
			b = -b;
			ch = true;
		}
		int dif = abs(x1 - x2);
		if(a <= 0){
			if(dif <= b)
				cout << "FIRST" << endl << (ch ? x1 : x2) << endl;
			else cout << "DRAW" << endl;
		}
		else{
			int rem = dif % (a + b);
			if(rem == 0)
				cout << "SECOND" << endl;
			else if(rem >= a && rem <= b)
				cout << "FIRST" << endl << (ch ? x2 - rem : x1 + rem) << endl;
			else cout << "DRAW" << endl;
		}
	}
	return 0;
}