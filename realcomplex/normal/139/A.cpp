#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n;
	cin >> n;
	int sk[7];
	for(int i = 0;i<7;i++){
		cin >> sk[i];
	}
	int sum = 0;
	while(sum < n){
		for(int i = 0;i<7;i++){
			sum += sk[i];
			if(sum >= n){
				cout << i + 1;
				break;
			}
		}
	}
	return 0;
}