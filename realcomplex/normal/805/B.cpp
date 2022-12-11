#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n;
	cin >> n;
	int write = 0;
	if(n % 2 == 0){
		for(int i = 0;i<n/2;i++){
			if(write == 0){
				cout << "ba";
				write = 1;
			}
			else{
				cout << "ab";
				write = 0;
			}
		}
	}
	else{
		for(int i = 0;i<n/2;i++){
			if(write == 0){
				cout << "ba";
				write = 1;
			}
			else{
				cout << "ab";
				write = 0;
			}
		}
		if(write == 0){
			cout << "b";
		}
		else{
			cout << "a";
		}
	}
	return 0;
}