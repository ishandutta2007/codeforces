#include <bits/stdc++.h>

using namespace std;

double n;

int main(){

	cin >> n;

	for(double aa=1;aa<=10;aa++)
		for(double h=1;h<=10;h++)
			if(abs(aa*h/2/sqrt(aa*aa/4+h*h)-n)<=0.0001){
				cout << aa << ' ' << h << endl;
				return 0;
			}
return 0;
}