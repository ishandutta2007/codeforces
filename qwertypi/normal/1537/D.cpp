#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int r = n, d = 0;
		while(r % 2 == 0) r /= 2, d++;
		if(d == 0){
			cout << "Bob" << endl;
		}else if(r != 1){
			cout << "Alice" << endl;
		}else{
			if(d % 2){
				cout << "Bob" << endl;
			}else{
				cout << "Alice" << endl;
			}
		}
	}
}