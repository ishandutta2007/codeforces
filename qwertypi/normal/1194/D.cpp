#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string> 
#include <set>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n, k;
		cin >> n >> k;
		switch(k % 3){
			case 0:
				n %= k + 1;
				if(n % 3 == 0 && n != k){
					cout << "Bob" << endl;
				}else{
					cout << "Alice" << endl;
				}
				break;
			case 1:
			case 2:
				if(n % 3 == 0){
					cout << "Bob" << endl;
				}else{
					cout << "Alice" << endl;
				}
				break;
		}
	}
	return 0;
}