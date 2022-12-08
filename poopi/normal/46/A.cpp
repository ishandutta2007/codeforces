#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int p = 0;
		for(int i = 1; i < n; i++){
			p = (p + i) % n;
			if(i > 1) cout << ' ';
			cout << p + 1;
		}
		cout << endl;
	}
	return 0;
}